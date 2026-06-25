class Solution {
public:
    string reverseVowels(string s) {
       
        string v = "aeiouAEIOU";
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
           
            while (left < right && v.find(s[left]) == string::npos) {
                left++;
            }
            
            while (left < right && v.find(s[right]) == string::npos) {
                right--;
            }
            
           
            if (left < right) {
                swap(s[left], s[right]);
                left++;  
                right--; 
            }
        }
        
        return s;
    }
};
