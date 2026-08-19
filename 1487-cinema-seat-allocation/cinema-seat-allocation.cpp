class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        std::unordered_map<int, int> row_masks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Only seats 2 to 9 impact group placements
            if (col >= 2 && col <= 9) {
                row_masks[row] |= (1 << (col - 2));
            }
        }
        
        int max_groups = n * 2;
        
        int left_mask = 15;   
        int right_mask = 240; 
        int mid_mask = 60;    
        
        for (auto const& [row, mask] : row_masks) {
            // Subtract the default 2 groups assumed for this row
            max_groups -= 2;
            
            bool left_free = (mask & left_mask) == 0;
            bool right_free = (mask & right_mask) == 0;
            
            if (left_free && right_free) {
                max_groups += 2; // Both left and right blocks are perfectly available
            } else if (left_free || right_free || (mask & mid_mask) == 0) {
                max_groups += 1; // At least one valid configuration can be seated
            }
        }
        
        return max_groups;
    }
};