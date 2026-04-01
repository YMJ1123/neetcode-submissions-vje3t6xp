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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        // TreeNode* l = root->left;
        // TreeNode* r = root->right;
        // if (p->val < l->val && q->val < l->val){
        //     lowestCommonAncestor(l, p, q);
        // }
        // if (p->val > r->val && q->val > r->val){
        //     lowestCommonAncestor(r, p, q);
        // }

        if (p->val < root->val && q->val < root->val){
            lca = lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val){
            lca = lowestCommonAncestor(root->right, p, q);
        }
        else{
            // if (p->val == root->val){
            //     return root;
            // } 
            lca = root;
        }

        return lca;

    }
};
