#include <unordered_map>

using namespace std;

class Solution {
private:
    int totalPaths = 0;
    unordered_map<long long, int> prefixSumMap;

    void dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return;

     
        currentSum += node->val;

       
        if (prefixSumMap.count(currentSum - targetSum)) {
            totalPaths += prefixSumMap[currentSum - targetSum];
        }

      
        prefixSumMap[currentSum]++;

        
        dfs(node->left, currentSum, targetSum);
        dfs(node->right, currentSum, targetSum);

        
        prefixSumMap[currentSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        totalPaths = 0;
        prefixSumMap.clear();
        
        
        prefixSumMap[0] = 1;
        
        dfs(root, 0, targetSum);
        return totalPaths;
    }
};
