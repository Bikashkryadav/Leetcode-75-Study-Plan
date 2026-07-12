
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        
        std::unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        
       
        std::unordered_set<int> unique_counts;
        for (auto& pair : counts) {
            int frequency = pair.second;
            
           
            if (unique_counts.find(frequency) != unique_counts.end()) {
                return false;
            }
            unique_counts.insert(frequency);
        }
        
        return true;
    }
};
