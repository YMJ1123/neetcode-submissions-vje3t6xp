class PrefixTree {
private:
    // 定義節點的結構
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
    
    TrieNode* root; // 樹的起點 (大廳)

public:
    PrefixTree() {
        root = new TrieNode(); // 宇宙大爆炸，建立第一個大廳節點
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            // 如果這扇門沒開過，就建一個新的轉運站
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            // 走進去
            curr = curr->children[index];
        }
        // 🚨 關鍵 1：迴圈結束，單字插完了，把最後停下來的節點蓋上「單字結尾」的印章！
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            // 走到一半沒路了，代表這棵樹根本沒這個字
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        // 🚨 關鍵 2：雖然路順利走完了，但必須確定這裡「真的是一個單字的結尾」
        // 例如：樹裡有 "apple"，你 search("app")，會走到這裡，
        // 但 "app" 的 isEndOfWord 是 false，所以會正確回傳 false！
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            // 走到一半沒路了，代表沒有這個前綴
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        // 🚨 關鍵 3：路順利走完了！因為我們只在乎它是不是「前綴」，
        // 所以不用管它是不是單字的結尾，直接大方回傳 true 即可！
        return true;
    }
};