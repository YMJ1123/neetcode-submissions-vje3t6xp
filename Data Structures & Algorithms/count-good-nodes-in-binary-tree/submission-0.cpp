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

class Solution {
public:
    int dfs(TreeNode* node, int max_val) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0; // number of good node of this node and its children

        if (node->val >= max_val){
            max_val = node->val;
            count = 1;
        }

        count += dfs(node->left, max_val);
        count += dfs(node->right, max_val);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);        
    }
};
