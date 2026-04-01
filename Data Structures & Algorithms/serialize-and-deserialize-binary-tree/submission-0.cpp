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

class Codec {
private:
    // 輔助函式：用來遞迴序列化
    void encode(TreeNode* node, string& s) {
        if (node == nullptr){
            s += "N,";
        }
        else{
            s += to_string(node->val);
            s += ",";
            encode(node->left, s);
            encode(node->right, s);
        }
    }
    // 輔助函式：用來遞迴反序列化 (傳入 stringstream 方便切割字串)
    TreeNode* decode(stringstream& ss) {
        string val;
        if (!getline(ss, val, ',')) {
            return nullptr;
        }
        // getline(ss, val, ',');

        if (val=="N"){
            return nullptr;
        }else{
            int v = stoi(val);
            TreeNode* root = new TreeNode(v);

            root->left = decode(ss);
            root->right = decode(ss);
            return root;
        }

    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        encode(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data); // 把字串轉換成資料流
        return decode(ss);
    }
};
