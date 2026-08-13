#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

class Solution {
private:
    // Tracks segment lengths to quickly fetch the maximum
    std::multiset<int> lengths;
    // Maps the start index of a segment to its end index (inclusive)
    std::map<int, int> segments;
    
    // Helper to add a new segment [l, r]
    void addSegment(int l, int r) {
        segments[l] = r;
        lengths.insert(r - l + 1);
    }
    
    // Helper to remove an existing segment starting at index l
    void removeSegment(int l) {
        int r = segments[l];
        lengths.erase(lengths.find(r - l + 1));
        segments.erase(l);
    }

public:
    std::vector<int> longestRepeating(std::string s, std::string queryCharacters, std::vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        std::vector<int> ans(k);
        
        // 1. Initialize segments for the initial string
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            addSegment(i, j - 1);
            i = j;
        }
        
        // 2. Process each query dynamically
        for (int i = 0; i < k; ++i) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            
            // If character doesn't change, max length remains the same
            if (s[idx] == c) {
                ans[i] = *lengths.rbegin();
                continue;
            }
            
            // Locate the segment containing the index to be updated
            auto it = segments.upper_bound(idx);
            --it;
            int l = it->first;
            int r = it->second;
            
            // Remove the old segment containing 'idx'
            removeSegment(l);
            
            // Split the segment if necessary
            if (l < idx) {
                addSegment(l, idx - 1);
            }
            if (r > idx) {
                addSegment(idx + 1, r);
            }
            
            // Update character in string
            s[idx] = c;
            
            // Create a single-character segment for the updated index
            addSegment(idx, idx);
            
            // Try to merge the new single segment with its right neighbour
            if (idx + 1 < n && s[idx] == s[idx + 1]) {
                int r_neigh_l = idx + 1;
                int r_neigh_r = segments[r_neigh_l];
                
                removeSegment(idx);
                removeSegment(r_neigh_l);
                addSegment(idx, r_neigh_r);
            }
            
            // Try to merge the current segment with its left neighbour
            auto curr_it = segments.upper_bound(idx);
            --curr_it;
            int curr_l = curr_it->first;
            int curr_r = curr_it->second;
            
            if (curr_l > 0 && s[curr_l] == s[curr_l - 1]) {
                auto left_it = segments.upper_bound(curr_l - 1);
                --left_it;
                int left_l = left_it->first;
                
                removeSegment(left_l);
                removeSegment(curr_l);
                addSegment(left_l, curr_r);
            }
            
            // The maximum length is always the last element of our multiset
            ans[i] = *lengths.rbegin();
        }
        
        return ans;
    }
};
