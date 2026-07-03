class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int operations = 0;
        
        while (left < right) {
            int current_sum = nums[left] + nums[right];
            
            if (current_sum == k) {
                operations++;
                left++;
                right--;
            } else if (current_sum < k) {
                left++;
            } else {
                right--;
            }
        }
        
        return operations;
    }
};
