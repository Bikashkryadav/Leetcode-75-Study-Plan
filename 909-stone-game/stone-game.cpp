class Solution {
public:
    bool stoneGame(vector<int>& piles) {
         int n = piles.size();
       
        vector<int> dp = piles; 
        
     
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                
                dp[i] = max(piles[i] - dp[i + 1], piles[j] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
};