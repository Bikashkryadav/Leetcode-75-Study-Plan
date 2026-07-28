
class Solution {
public:
    int goodNodes(TreeNode* root) {
      
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int max_so_far) {
      
        if (node == nullptr) {
            return 0;
        }

        int count = 0;
     
        if (node->val >= max_so_far) {
            count = 1;
        }

      
        max_so_far = std::max(max_so_far, node->val);

      
        count += dfs(node->left, max_so_far);
        count += dfs(node->right, max_so_far);

        return count;
    }
};
