class Solution {
public:
    long long sumAndMultiply(int n) {
         std::string s = std::to_string(n);
        std::string nonZeroStr = "";
        long long digitSum = 0;

        for (char ch : s) {
            if (ch != '0' && ch != '-') { 
                nonZeroStr += ch;
                digitSum += (ch - '0');
            }
        }

        if (nonZeroStr.empty()) {
            return 0;
        }
        long long x = std::stoll(nonZeroStr);

        return x * digitSum;
    }
};