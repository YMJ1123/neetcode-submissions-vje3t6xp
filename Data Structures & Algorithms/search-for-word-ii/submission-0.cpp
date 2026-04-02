#include <vector>
#include <string>

using namespace std;

// 1. 特製版字典樹節點
struct TrieNode {
    TrieNode* children[26];
    string word; // 存放完整的單字，如果不是結尾就是空字串 ""

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;

    // 將所有單字建構進字典樹
    void buildTrie(vector<string>& words) {
        root = new TrieNode();
        for (string w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int index = c - 'a';
                if (curr->children[index] == nullptr) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            // 🚨 走到字尾，直接把整個單字存進節點裡！
            curr->word = w; 
        }
    }

    // 棋盤上的 DFS，這次多帶了一個 TrieNode 當導遊
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        // 邊界檢查，或是遇到走過的路 ('#')
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') {
            return;
        }

        char letter = board[r][c];
        int index = letter - 'a';

        // 🚨 神級剪枝：如果字典樹裡沒有這個字母的路，直接回頭！
        if (node->children[index] == nullptr) {
            return;
        }

        // 順利通過，跟著 Trie 往下走一步
        TrieNode* nextNode = node->children[index];

        // 如果這個節點裝有單字，代表我們找到答案了！
        if (nextNode->word != "") {
            result.push_back(nextNode->word);
            // 🚨 去重關鍵：找到後就把節點裡的單字清空，避免同一個單字被找到兩次！
            nextNode->word = ""; 
        }

        // 標記為走過 (一放！)
        board[r][c] = '#';

        // 往四個方向繼續探索
        dfs(board, r + 1, c, nextNode); // 下
        dfs(board, r - 1, c, nextNode); // 上
        dfs(board, r, c + 1, nextNode); // 右
        dfs(board, r, c - 1, nextNode); // 左

        // 恢復原狀 (一拿！Backtracking)
        board[r][c] = letter;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. 建立字典樹
        buildTrie(words);

        int rows = board.size();
        int cols = board[0].size();

        // 2. 遍歷棋盤，每個格子都當作起點出發一次
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // 從 root 開始配對
                dfs(board, r, c, root);
            }
        }

        return result;
    }
};