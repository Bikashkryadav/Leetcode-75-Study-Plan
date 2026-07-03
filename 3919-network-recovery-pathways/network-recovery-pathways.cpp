class Solution {
private:
    struct Edge {
        int to;
        long long cost;
    };

    // Feasibility check using Topo-Sort DP since the graph is a DAG
    bool isValid(int n, const vector<vector<Edge>>& graph, const vector<int>& indegree, 
                 const vector<bool>& online, long long k, long long min_allowed_edge) {
        
        // dist[i] stores the minimum total cost to reach node i
        // Using LLONG_MAX to represent infinity
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        // Copy indegree to safely modify it during Kahn's algorithm
        vector<int> current_indegree = indegree;
        queue<int> q;

        // Initialize queue with all source nodes (indegree == 0)
        for (int i = 0; i < n; ++i) {
            if (current_indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes in topological order
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Relax outgoing edges if the current node is reachable
            if (dist[u] != LLONG_MAX) {
                for (const auto& edge : graph[u]) {
                    int v = edge.to;
                    
                    // Filter 1: Edge cost must be >= our binary search bottleneck
                    // Filter 2: Destination node must be online
                    if (edge.cost >= min_allowed_edge && online[v]) {
                        if (dist[u] + edge.cost < dist[v]) {
                            dist[v] = dist[u] + edge.cost;
                        }
                    }
                }
            }

            // Standard Topo-Sort step: reduce indegree of neighbors
            for (const auto& edge : graph[u]) {
                int v = edge.to;
                if (--current_indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Return true if the destination is reachable within total budget k
        return dist[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<Edge>> graph(n);
        vector<int> indegree(n, 0);
        vector<long long> unique_costs;

        // Step 1: Construct the graph and calculate indegrees
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            long long cost = edge[2];
            
            graph[u].push_back({v, cost});
            indegree[v]++;
            unique_costs.push_back(cost);
        }

        // Step 2: Extract sorted unique edge costs for binary search
        sort(unique_costs.begin(), unique_costs.end());
        unique_costs.erase(unique(unique_costs.begin(), unique_costs.end()), unique_costs.end());

        // Step 3: Binary Search on the sorted scores
        int low = 0;
        int high = unique_costs.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long target_min_edge = unique_costs[mid];

            if (isValid(n, graph, indegree, online, k, target_min_edge)) {
                result = target_min_edge; // Valid route found; try for a higher bottleneck
                low = mid + 1;
            } else {
                high = mid - 1; // Path not possible; lower the constraint threshold
            }
        }

        return result;
    }
};