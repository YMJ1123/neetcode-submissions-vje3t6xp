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
    // 輔助函式：帶著上下限往下走
    bool dfs(TreeNode* node, long long min_val, long long max_val) {
        // 1. 終止條件：空節點是合法的 BST，回傳 true
        if (node == nullptr) {
            return true;
        }

        // 2. 檢查自己有沒有乖乖待在規定範圍內？
        // 如果我的值 <= 下限，或者 >= 上限，代表我違規了！
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // 3. 遞迴檢查左右小孩
        // 左小孩：所有的值必須小於我，所以「上限」變成 node->val
        bool leftIsValid = dfs(node->left, min_val, node->val);
        
        // 右小孩：所有的值必須大於我，所以「下限」變成 node->val
        bool rightIsValid = dfs(node->right, node->val, max_val);

        // 左右兩邊都必須合法，整棵樹才合法
        return leftIsValid && rightIsValid;
    }

    bool isValidBST(TreeNode* root) {
        // 遊戲開始！一開始上下限是無限大與無限小
        // 我們用 C++ 內建的 LONG_MIN 和 LONG_MAX 代表負無限與正無限
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};