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
    int count = 0;
    int ans = 0;
public:
    void inorderDFS(TreeNode* node, int k) {
        if (node == nullptr || count >= k) {
            return;
        }

        inorderDFS(node->left, k);

        count++; // go through a new node
        if (count==k){
            ans = node->val;
            return;
        }

        inorderDFS(node->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        inorderDFS(root, k);

        return ans;
    }
};
