class Solution {
public:
    int minimumPushes(string word) {
        std::vector<int> frequencies(26, 0);
        for (char c : word) {
            frequencies[c - 'a']++;
        }
        
        std::sort(frequencies.rbegin(), frequencies.rend());
        
        int totalPushes = 0;
       
        for (int i = 0; i < 26; ++i) {
            if (frequencies[i] == 0) break; 
            
            int pushesNeeded = (i / 8) + 1;
            totalPushes += frequencies[i] * pushesNeeded;
        }
        
        return totalPushes;
    }
};