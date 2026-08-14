class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> char_counts(26, 0);
        int left = 0;
        int max_length = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char_counts[s[right] - 'a']++;
            
            while (char_counts[s[right] - 'a'] > 2) {
                char_counts[s[left] - 'a']--;
                left++;
            }
            
            max_length = std::max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};