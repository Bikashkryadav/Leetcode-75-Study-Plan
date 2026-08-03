class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
         int n = stoneValue.size();
        
       
        std::vector<int> dp(4, 0);
        
       
        for (int i = n - 1; i >= 0; --i) {
            int max_score = INT_MIN;
            int current_take = 0;
            
           
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                current_take += stoneValue[i + k - 1];
            
                int current_score = current_take - dp[(i + k) % 4];
                max_score = std::max(max_score, current_score);
            }
            
            dp[i % 4] = max_score;
        }
        
        
        int alice_relative_score = dp[0];
        
        if (alice_relative_score > 0) return "Alice";
        if (alice_relative_score < 0) return "Bob";
        return "Tie";
    }
};