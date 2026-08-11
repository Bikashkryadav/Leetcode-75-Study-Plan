class Solution {
public:
    int missingInteger(vector<int>& nums) {
                int prefix_sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            } else {
                break;
            }
        }
        
        unordered_set<int> elements(nums.begin(), nums.end());
        
        while (elements.count(prefix_sum)) {
            prefix_sum++;
        }
        
        return prefix_sum;
    }
};