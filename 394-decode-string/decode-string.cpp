class Solution {
public:
    string decodeString(string s) {
        std::stack<std::string> strStack;
        std::stack<int> numStack;
        std::string currentString = "";
        int currentNumber = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
               
                currentNumber = currentNumber * 10 + (ch - '0');
            } 
            else if (ch == '[') {
               
                numStack.push(currentNumber);
                strStack.push(currentString);
                currentNumber = 0;
                currentString = "";
            } 
            else if (ch == ']') {
                
                int k = numStack.top();
                numStack.pop();
                
                std::string prevString = strStack.top();
                strStack.pop();

                std::string repeatedString = "";
                for (int i = 0; i < k; ++i) {
                    repeatedString += currentString;
                }

               
                currentString = prevString + repeatedString;
            } 
            else {
               
                currentString += ch;
            }
        }

        return currentString;
    }
};