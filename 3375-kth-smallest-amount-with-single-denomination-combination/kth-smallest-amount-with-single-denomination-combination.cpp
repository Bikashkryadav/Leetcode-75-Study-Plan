
class Solution {
private:
    // Helper function to calculate LCM safely without overflow
    long long getLcm(long long a, long long b) {
        return (a / std::gcd(a, b)) * b;
    }

    // Counts how many valid amounts exist <= target using Inclusion-Exclusion
    long long countValidAmounts(long long target, const vector<int>& coins) {
        long long totalCount = 0;
        int n = coins.size();
        int totalSubsets = 1 << n; // 2^n configurations

        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long currentLcm = 1;
            int elementCount = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    elementCount++;
                    currentLcm = getLcm(currentLcm, coins[i]);
                    
                    // Optimization: If LCM exceeds target, target / currentLcm will be 0
                    if (currentLcm > target) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            // PIE Rule: Add if odd number of elements, subtract if even
            if (elementCount % 2 == 1) {
                totalCount += (target / currentLcm);
            } else {
                totalCount -= (target / currentLcm);
            }
        }
        return totalCount;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Find the absolute minimum coin to establish baseline bounds
        long long minCoin = *min_element(coins.begin(), coins.end());
        
        long long low = minCoin;
        long long high = minCoin * k; // Worst-case upper bound
        long long result = high;

        // Binary search for the exact value
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (countValidAmounts(mid, coins) >= k) {
                result = mid;       // Valid value, try to find a smaller one
                high = mid - 1;
            } else {
                low = mid + 1;      // Not enough values, search higher
            }
        }

        return result;
    }
};
