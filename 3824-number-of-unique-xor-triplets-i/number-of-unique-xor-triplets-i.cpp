class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return n;
        }
        
        int msb = 0;
        while ((1 << msb) <= n) {
            msb++;
        }
        return (1 << msb);
    }
};