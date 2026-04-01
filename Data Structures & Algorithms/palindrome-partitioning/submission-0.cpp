#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // 輔助函式：檢查字串 s 從左邊 left 到右邊 right 這段是不是迴文
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false; // 只要頭尾不一樣，就不是迴文
            }
            left++;
            right--;
        }
        return true;
    }

    // start: 目前我們站在字串的哪個位子準備下刀
    // current: 目前背包裡裝了哪些切好的迴文塊
    void dfs(int start, const string& s, vector<string>& current, vector<vector<string>>& ans) {
        // 1. 終止條件：刀子已經走到字串盡頭了，代表切到底了！
        if (start == s.length()) {
            ans.push_back(current);
            return;
        }

        // 2. 嘗試各種切法：從 start 開始，一格一格往右邊試著切下去 (end)
        for (int end = start; end < s.length(); end++) {
            
            // 3. 剪枝：如果切下來的這塊 (s[start] 到 s[end]) 是迴文，我們才繼續走！
            if (isPalindrome(s, start, end)) {
                // 擷取字串：substr(起點, 長度)
                // 長度就是 end - start + 1
                current.push_back(s.substr(start, end - start + 1)); // 一放！
                
                // 帶著剩下的字串 (從 end + 1 開始)，繼續往下切
                dfs(end + 1, s, current, ans);
                
                current.pop_back(); // 一拿！ (Backtracking 恢復原狀，準備嘗試下一個切法)
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        
        // 遊戲開始：從第 0 個位子準備下第一刀
        dfs(0, s, current, ans);
        
        return ans;
    }
};