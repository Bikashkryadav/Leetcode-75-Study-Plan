/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>

class Solution {
private:

    void getLeaves(TreeNode* root, std::vector<int>& leaves) {
        if (root == nullptr) {
            return;
        }
        
     
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            return;
        }
      
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1;
        std::vector<int> leaves2;
        
      
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        
        return leaves1 == leaves2;
    }
};
