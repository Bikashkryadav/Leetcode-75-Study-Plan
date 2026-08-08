class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        std::vector<int> last_pos(m, -1);
        
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                last_pos[j] = i;
                j--;
            }
        }
        
        std::vector<int> ans;
        bool can_mismatch = true;
        j = 0; 
        
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (can_mismatch && (j == m - 1 || last_pos[j + 1] > i)) {
                ans.push_back(i);
                can_mismatch = false;
                j++;
            }
        }
        
        if (ans.size() < m) {
            return {};
        }
        
        return ans;
    }
};