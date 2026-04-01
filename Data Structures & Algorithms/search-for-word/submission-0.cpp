#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // r, c: 目前走到棋盤的哪一列、哪一欄
    // index: 目前正在找 word 裡面的第幾個字母
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // 1. 終止條件：如果 index 已經等於 word 的長度，代表全部字母都找到了！
        if (index == word.length()) {
            return true;
        }

        // 2. 邊界與失敗條件檢查 (非常重要！)
        // 條件 A: r 或 c 超出棋盤的範圍 (小於 0 或大於等於邊界)
        // 條件 B: 目前格子裡的字母，根本不是我們要找的 word[index]
        // (注意：因為我們走過的格子會變成 '#'，所以如果踩到 '#' 也會在這裡被退貨！)
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // 3. 標記已走過 (一放！)
        char temp = board[r][c]; // 先把原本的字母記下來
        board[r][c] = '#';       // 留下走過的記號

        // 4. 往上下左右四個方向探索！
        // 只要這四個方向有「任何一條路」回傳 true，res 就是 true
        // bool res = dfs(上) || dfs(下) || dfs(左) || dfs(右);
        bool res = dfs(board, word, r - 1, c, index + 1) || dfs(board, word, r + 1, c, index + 1) || dfs(board, word, r, c - 1, index + 1) || dfs(board, word, r, c + 1, index + 1);                
                   
        // 5. 恢復原狀 (一拿！Backtracking 發威)
        board[r][c] = temp;

        // 回傳這條路到底通不通
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // 雙層迴圈：把每一個格子都當作起點試試看
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // 如果這個起點能一路找完所有的字 (回傳 true)
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        
        // 全部起點都試過了，還是找不到
        return false;
    }
};