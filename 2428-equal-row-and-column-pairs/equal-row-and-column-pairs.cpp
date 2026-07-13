class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
         std::map<std::vector<int>, int> row_counts;
        int n = grid.size();
        
        
        for (const auto& row : grid) {
            row_counts[row]++;
        }
        int total_pairs = 0;
        for (int c = 0; c < n; ++c) {
            std::vector<int> col(n);
            for (int r = 0; r < n; ++r) {
                col[r] = grid[r][c];
            }
            
            if (row_counts.count(col)) {
                total_pairs += row_counts[col];
            }
        }
        
        return total_pairs;
    }
};