#include <string>

using namespace std;

class WordDictionary {
private:
    // 1. 照抄上一題的節點設計
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;

    // 2. Trie 結合 DFS 的精華所在！
    // index: 目前正在比對 word 的第幾個字元
    // node: 目前走到字典樹的哪一個轉運站
    bool searchHelper(const string& word, int index, TrieNode* node) {
        // A. 終止條件：如果字串都比對完了，看看目前這個節點是不是單字結尾
        if (index == word.length()) {
            return node->isEndOfWord;
        }

        char c = word[index];

        // B. 遇到萬用字元 '.'：進入平行時空探索模式 (Backtracking / DFS)
        if (c == '.') {
            // 把 26 扇門都巡過一次
            for (int i = 0; i < 26; i++) {
                // 只要這扇門有開 (不是 nullptr)，就走進去試試看
                if (node->children[i] != nullptr) {
                    // 帶著 index + 1 繼續往下找。
                    // 只要「任何一條路」回傳 true，代表找到了，直接回傳 true！
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
            // 26 扇門都試過了，還是找不到，這條路死胡同
            return false;
        } 
        // C. 遇到普通字母：乖乖走一般 Trie 的路線
        else {
            int childIndex = c - 'a';
            // 沒路了，直接失敗
            if (node->children[childIndex] == nullptr) {
                return false;
            }
            // 順利的話，就往下一層繼續找
            return searchHelper(word, index + 1, node->children[childIndex]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        // 這裡完全照抄上一題的 insert 邏輯
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        // 從第 0 個字元，以及大廳 root 開始呼叫我們的 DFS
        return searchHelper(word, 0, root);
    }
};