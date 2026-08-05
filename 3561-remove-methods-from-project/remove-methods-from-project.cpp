class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        std::vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }


        std::vector<bool> isSuspicious(n, false);
        std::queue<int> q;
        
        q.push(k);
        isSuspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!isSuspicious[neighbor]) {
                    isSuspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

     
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
               
                std::vector<int> allMethods(n);
                std::iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        std::vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                remaining.push_back(i);
            }
        }

        return remaining;
    }
};