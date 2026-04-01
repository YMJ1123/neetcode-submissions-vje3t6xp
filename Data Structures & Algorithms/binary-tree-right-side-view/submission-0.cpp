class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; // 這次只需要一維陣列

        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            // 負責處理「這一層」的迴圈
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // 🔑 關鍵判斷：
                // 如果目前這個 node 是這層的「最後一個」人，
                // 就把它加進最終答案裡！
                // (提示：怎麼用 i 和 levelSize 來判斷他是最後一個？)
                if ( i == levelSize-1 ) {
                    ans.push_back(node->val);
                }

                // 讓左右小孩排隊 (跟上一題完全一樣)
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        
        return ans;
    }
};