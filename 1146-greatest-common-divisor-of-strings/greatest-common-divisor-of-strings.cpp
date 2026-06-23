class Solution {
public:
int getGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        int s1 = str1.length();
        int s2 = str2.length();
        
        int gcdLength = getGCD(s1,s2);
        
        return str1.substr(0, gcdLength);
    }
};
