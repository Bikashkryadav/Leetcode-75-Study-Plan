#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Safely calculates the multinomial combinations.
    // Clamps early to 'cap' if the count exceeds 'k' to avoid any overflow.
    long long countPermutations(const vector<int>& freq, long long cap) {
        long long total_perms = 1;
        int current_total = 0;

        for (int f : freq) {
            if (f <= 0) continue;
            
            for (int i = 1; i <= f; ++i) {
                current_total++;
                
                // Mathematical check to see if total_perms * current_total / i > cap
                // equivalent to: total_perms > (cap * i) / current_total
                if (total_perms > (cap * i) / current_total) {
                    return cap; 
                }
                
                total_perms = total_perms * current_total / i;
            }
        }
        return total_perms;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = '#';
        vector<int> half_freq(26, 0);
        int half_len = 0;

        // Step 1: Validate palindrome feasibility
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
            half_freq[i] = count[i] / 2;
            half_len += half_freq[i];
        }

        if (odd_count > 1) return "";

        long long cap = k;

        // Step 2: Validate if k is within bounds of total unique permutations
        long long total_perms = countPermutations(half_freq, cap);
        if (k > total_perms) return "";

        string first_half = "";
        long long current_k = k;

        // Step 3: Construct the first half greedily character-by-character
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] > 0) {
                    // Try placing character 'a' + c at current position
                    half_freq[c]--;
                    
                    long long perms = countPermutations(half_freq, current_k);
                    
                    if (current_k <= perms) {
                        first_half += (char)('a' + c);
                        break; // Confirmed choice for position i
                    } else {
                        current_k -= perms;
                        half_freq[c]++; // Backtrack
                    }
                }
            }
        }

        // Step 4: Mirror the first half to form the final palindrome
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        if (mid_char != '#') {
            return first_half + mid_char + second_half;
        }
        return first_half + second_half;
    }
};
