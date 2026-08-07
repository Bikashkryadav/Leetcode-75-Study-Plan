#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    // Holds counts of needed prime factors: 2, 3, 5, 7
    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    // Factorize t into prime factors 2, 3, 5, 7. 
    // Returns a flag indicating if it's possible (no factors > 7).
    pair<Factors, bool> getFactors(long long t) {
        Factors f;
        while (t % 2 == 0) { f.c2++; t /= 2; }
        while (t % 3 == 0) { f.c3++; t /= 3; }
        while (t % 5 == 0) { f.c5++; t /= 5; }
        while (t % 7 == 0) { f.c7++; t /= 7; }
        if (t > 1) return {f, false}; // t has prime factors like 11, 13, etc.
        return {f, true};
    }

    // Calculates the absolute minimum number of digits (1-9) needed 
    // to satisfy the remaining required factor counts.
    int minDigitsNeeded(Factors req) {
        int r2 = max(0, req.c2);
        int r3 = max(0, req.c3);
        int r5 = max(0, req.c5); 
        int r7 = max(0, req.c7);

        int count = 0;
        // Greedily bundle 3s into 9s (two 3s per digit)
        count += (r3 + 1) / 2;
        // Greedily bundle 2s into 8s (three 2s per digit)
        count += r2 / 3;
        r2 %= 3;

        // If we have a leftover 3 (odd count originally), it can absorb one 2 to make a '6'
        if (r3 % 2 != 0 && r2 > 0) {
            r2--; 
        }
        // Leftover 2s can be bundled into 4s (two 2s per digit) or left as a 2
        if (r2 > 0) {
            count += (r2 + 1) / 2;
        }

        // 5 and 7 can only be represented by themselves
        count += r5;
        count += r7;
        return count;
    }

    // Deducts the prime factors of a digit from the required counts
    Factors reduce(Factors req, int digit) {
        while (digit % 2 == 0) { req.c2--; digit /= 2; }
        while (digit % 3 == 0) { req.c3--; digit /= 3; }
        while (digit % 5 == 0) { req.c5--; digit /= 5; }
        while (digit % 7 == 0) { req.c7--; digit /= 7; }
        return req;
    }

    // Generates the lexicographically smallest suffix of a given length
    string generateSmallestSuffix(int length, Factors req) {
        string suffix = "";
        for (int i = 0; i < length; ++i) {
            for (int d = 1; d <= 9; ++d) {
                Factors next_req = reduce(req, d);
                if (minDigitsNeeded(next_req) <= length - 1 - i) {
                    suffix += to_string(d);
                    req = next_req;
                    break;
                }
            }
        }
        return suffix;
    }

public:
    string smallestNumber(string num, long long t) {
        auto [target, isValid] = getFactors(t);
        if (!isValid) return "-1"; 

        int n = num.length();
        vector<Factors> prefix_factors(n + 1);
        int first_zero = -1;

        // Compute prefix factors up to the first '0'
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            prefix_factors[i + 1] = reduce(prefix_factors[i], num[i] - '0');
        }

        // Limit maximum length check context if '0' is present
        int max_prefix_len = (first_zero == -1) ? n : first_zero;

        for (int i = max_prefix_len; i >= 0; --i) {
            Factors current_req = target;
         
            current_req.c2 += prefix_factors[i].c2;
            current_req.c3 += prefix_factors[i].c3;
            current_req.c5 += prefix_factors[i].c5;
            current_req.c7 += prefix_factors[i].c7;

          
            if (i == n) {
                if (minDigitsNeeded(current_req) <= 0) return num;
                continue;
            }

            int start_digit = (num[i] - '0') + 1;
            for (int d = start_digit; d <= 9; ++d) {
                Factors next_req = reduce(current_req, d);
                int rem_len = n - 1 - i;

                if (minDigitsNeeded(next_req) <= rem_len) {
                    string prefix_str = num.substr(0, i) + to_string(d);
                    string suffix_str = generateSmallestSuffix(rem_len, next_req);
                    return prefix_str + suffix_str;
                }
            }
        }

        int required_len = max(n + 1, minDigitsNeeded(target));
        return generateSmallestSuffix(required_len, target);
    }
};
