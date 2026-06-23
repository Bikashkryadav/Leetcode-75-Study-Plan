class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        string result = "";
        int i=0,j=0;
        while(i<w1||j<w2){
            if(i<w1){
                result += word1[i];
                i++;
            }
            if(j<w2){
                result += word2[j];
                j++;
            }
        }
        return result;
    }
    
};