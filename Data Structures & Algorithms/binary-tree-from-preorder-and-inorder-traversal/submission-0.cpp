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
    unordered_map<int, int> inorder_map; // 用來瞬間找到 Root 在 inorder 的位置
    int preorder_index = 0;              // 記錄我們目前看到 preorder 的第幾個人

    // 輔助函式：in_left 和 in_right 是我們目前在 inorder 陣列裡面的「地盤範圍」
    TreeNode* build(vector<int>& preorder, int in_left, int in_right) {
        // 1. 終止條件：如果地盤的左界大於右界，代表這塊地盤沒有人了 (空節點)
        if (in_left > in_right) {
            return nullptr;
        }

        // 2. 找老大：從 preorder 抓出目前的 Root 的數值，並且把 index 往前推
        int root_val = preorder[preorder_index];
        preorder_index++;
        
        // 建立這個老大的節點
        TreeNode* root = new TreeNode(root_val);

        // 3. 劃分地盤：用 Hash Map 瞬間查出老大在 inorder 陣列裡的 index (分割點)
        int mid = inorder_map[root_val];

        // 4. 繼續辦案 (遞迴叫左右小孩去建樹)
        // 左子樹的地盤：從原本的左界開始，到老大的前一格 (mid - 1)
        root->left = build(preorder, in_left, mid-1);
        
        // 右子樹的地盤：從老大的下一格 (mid + 1) 開始，到原本的右界
        root->right = build(preorder, mid+1, in_right);

        // 5. 蓋好啦！回傳這棵樹的 Root
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
