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
    int height(TreeNode* root){
        int h;
        if (root == nullptr){
            return 0;
        }
        h = 1 + max(height(root->left),height(root->right));
        return h;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        if (isBalanced(root->left) && isBalanced(root->right) && (abs(height(root->left)-height(root->right))<=1)){
            return true; 
        }

        return false;
    }
};
