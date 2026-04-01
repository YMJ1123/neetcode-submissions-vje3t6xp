class Solution {
public:
    // 這個輔助函式會回傳高度。如果發現不平衡，就回傳 -1。
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // 1. 去問左子樹的高度
        int leftHeight = checkHeight(root->left);
        // 如果左子樹已經不平衡了，直接往上回報 -1，不用看了
        if (leftHeight == -1) return -1; 

        // 2. 去問右子樹的高度
        int rightHeight = checkHeight(root->right);
        // 如果右子樹不平衡了，直接往上回報 -1
        if (rightHeight == -1) return -1; 

        // 3. 左右子樹都很乖，那我們來檢查目前的節點平不平衡
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // 高度差大於 1，抓到了！回報 -1
        }

        // 4. 全部過關，回傳這棵樹的真實高度給上一層
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        // 只要 checkHeight 回傳的不是 -1，就代表整棵樹都是平衡的
        return checkHeight(root) != -1;
    }
};