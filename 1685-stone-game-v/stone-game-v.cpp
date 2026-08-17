#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

class Solution {
private:
    int memo[501][501];
    int pref[501];

    int getMaxScore(int i, int j, const std::vector<int>& stoneValue) {
        // Base case: only one stone left, no further split possible
        if (i == j) {
            return 0;
        }
        
        // Return cached result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int max_score = 0;
        
        // Try every possible split point k
        for (int k = i; k < j; ++k) {
            int left_sum = pref[k + 1] - pref[i];
            int right_sum = pref[j + 1] - pref[k + 1];
            
            int current_score = 0;
            if (left_sum < right_sum) {
                // Bob throws away the right row
                current_score = left_sum + getMaxScore(i, k, stoneValue);
            } else if (left_sum > right_sum) {
                // Bob throws away the left row
                current_score = right_sum + getMaxScore(k + 1, j, stoneValue);
            } else {
                // Sums are equal, Alice picks the path that yields the maximum score
                current_score = left_sum + std::max(getMaxScore(i, k, stoneValue), 
                                                    getMaxScore(k + 1, j, stoneValue));
            }
            
            max_score = std::max(max_score, current_score);
        }
        
        return memo[i][j] = max_score;
    }

public:
    int stoneGameV(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Initialize memoization table with -1
        std::memset(memo, -1, sizeof(memo));
        
        // Precompute prefix sums for O(1) range sum queries
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        
        return getMaxScore(0, n - 1, stoneValue);
    }
};
