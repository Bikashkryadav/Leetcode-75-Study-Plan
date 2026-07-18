class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [minIt, maxIt] = std::minmax_element(nums.begin(), nums.end());
        
        int smallest = *minIt;
        int largest = *maxIt;
        
        return std::gcd(smallest, largest);
    }
};