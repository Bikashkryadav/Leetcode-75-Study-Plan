class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(nums.begin(), nums.end());
         for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                dp[i] = std::max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }
        return dp[0] >= 0;
    }
};