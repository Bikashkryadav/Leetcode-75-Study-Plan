class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int maxLen = 1;
        
        if (count.count(1)) {
            int oneCount = count[1];
            maxLen = (oneCount % 2 == 0) ? oneCount - 1 : oneCount;
        }
        
        for (auto& [val, freq] : count) {
            if (val == 1) continue;
            
            int currentLen = 0;
            long long x = val;
            
            while (count.count(x) && count[x] >= 2) {
                currentLen += 2;
                if (x > 100000) { 
                    x = x * x;
                    break;
                }
                x = x * x;
            }
            
            if (count.count(x) && count[x] >= 1) {
                currentLen += 1;
            } else {
                currentLen -= 1;
            }
            
            maxLen = max(maxLen, currentLen);
        }
        
        return maxLen;
    }
};