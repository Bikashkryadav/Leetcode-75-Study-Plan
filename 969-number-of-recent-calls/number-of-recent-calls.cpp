class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        requests.push(t);
        int threshold = t - 3000;
        while (!requests.empty() && requests.front() < threshold) {
            requests.pop();
        }
        return requests.size();
    }
};
