class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int curr = n;
            int prod = 1;
            
            
            while (curr > 0) {
                prod *= (curr % 10);
                curr /= 10;
                
               
                if (prod == 0) {
                    break;
                }
            }
            
            
            if (prod % t == 0) {
                return n;
            }
            
            
            n++;
            }
    }
};