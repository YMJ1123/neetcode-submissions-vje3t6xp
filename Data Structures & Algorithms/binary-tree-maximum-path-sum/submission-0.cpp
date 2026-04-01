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
private:
    int max_sum = -1000000;
    int maxPathSumDFS(TreeNode* node) {
        if (node == nullptr){
            return 0;
        }
        int left_max_sum = maxPathSumDFS(node->left);
        int right_max_sum = maxPathSumDFS(node->right);
        
        int only_one_path = node->val + max(left_max_sum, right_max_sum);
        int both_path = left_max_sum + right_max_sum + node->val;
        max_sum = max(max_sum, only_one_path);
        max_sum = max(max_sum, both_path);

        return max(only_one_path, 0);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxPath = maxPathSumDFS(root);
        return max_sum;
    }
};
