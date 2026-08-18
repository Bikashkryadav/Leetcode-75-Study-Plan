class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n = nums.size();
        
        // Case 1: k equals 1
        if (k == 1) {
            std::unordered_map<int, int> counts;
            for (int num : nums) {
                counts[num]++;
            }
            int max_val = -1;
            for (auto& [num, count] : counts) {
                if (count == 1) {
                    max_val = std::max(max_val, num);
                }
            }
            return max_val;
        }

        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        // Case 3: 1 < k < n
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        int ans = -1;
        // Check if the first element appears exactly once
        if (counts[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        // Check if the last element appears exactly once
        if (counts[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};