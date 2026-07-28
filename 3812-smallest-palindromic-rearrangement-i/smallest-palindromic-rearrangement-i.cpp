class Solution {
public:
    string smallestPalindrome(string s) {
         std::map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

       
        int odd_count = 0;
        char mid_char = '\0';
        
        for (auto const& [ch, count] : counts) {
            if (count % 2 != 0) {
                odd_count++;
                mid_char = ch;
            }
        }

      
        if (odd_count > 1) {
            return "";
        }

     std::string left_half = "";
        for (auto const& [ch, count] : counts) {
           
            left_half.append(count / 2, ch);
        }

      
        std::string right_half = left_half;
        std::reverse(right_half.begin(), right_half.end());

        if (odd_count == 1) {
            return left_half + mid_char + right_half;
        }
        
        return left_half + right_half;
    }
};