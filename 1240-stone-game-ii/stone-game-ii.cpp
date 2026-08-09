class Solution {
    private:
    std::vector<int> suffix_sums;
    std::vector<std::vector<int>> memo;
    int n;

    int dp(int i, int m) {
        // Base case: If the current player can take all remaining piles
        if (i + 2 * m >= n) {
            return suffix_sums[i];
        }

        // Return cached result if already calculated
        if (memo[i][m] != -1) {
            return memo[i][m];
        }

        int max_stones = 0;
        
        // Try taking X piles where 1 <= X <= 2M
        for (int x = 1; x <= 2 * m; ++x) {
            int opponent_stones = dp(i + x, std::max(m, x));
            max_stones = std::max(max_stones, suffix_sums[i] - opponent_stones);
        }

        return memo[i][m] = max_stones;
    }

public:
    int stoneGameII(vector<int>& piles) {
         n = piles.size();
        suffix_sums.assign(n + 1, 0);
        
        // Step 1: Precalculate suffix sums from right to left
        for (int i = n - 1; i >= 0; --i) {
            suffix_sums[i] = suffix_sums[i + 1] + piles[i];
        }

        // Step 2: Initialize memoization table
        // Max possible value for M is n, so sizing M dimension to n + 1
        memo.assign(n, std::vector<int>(n + 1, -1));

        // Step 3: Start recursion from index 0 with M = 1
        return dp(0, 1);
    }
};