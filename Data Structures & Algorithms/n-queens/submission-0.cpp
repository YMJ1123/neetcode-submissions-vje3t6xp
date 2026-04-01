#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // 記錄危險區域的死亡筆記本
    unordered_set<int> cols;      // 記錄哪個 column 被佔用了
    unordered_set<int> posDiag;   // 記錄哪個 正對角線 (r + c) 被佔用了
    unordered_set<int> negDiag;   // 記錄哪個 負對角線 (r - c) 被佔用了

    void dfs(int r, int n, vector<string>& board, vector<vector<string>>& ans) {
        // 1. 終止條件：如果成功走到最後一列 (r == n)，代表 N 隻皇后都平安降落了！
        if (r == n) {
            ans.push_back(board);
            return;
        }

        // 2. 嘗試在這個 row (r) 的每一個 column (c) 放皇后
        for (int c = 0; c < n; c++) {
            
            // A. 剪枝檢查：如果這個位子 (r, c) 有危險，直接 continue 跳過找下一格！
            // 提示：檢查 c 是否在 cols 裡，(r+c) 是否在 posDiag 裡，(r-c) 是否在 negDiag 裡
            if (cols.contains(c) || posDiag.contains((r+c)) || negDiag.contains((r-c))) { continue; }

            // B. 放皇后 (一放！)
            // - 把 c 登記進 cols
            cols.emplace(c);
            // - 把 r + c 登記進 posDiag
            posDiag.emplace((r+c));
            // - 把 r - c 登記進 negDiag
            negDiag.emplace((r-c));
            // - 將棋盤 board[r][c] 變成 'Q'
            board[r][c] = 'Q';

            // 帶著更新後的棋盤，去下一列繼續放！
            dfs(r + 1, n, board, ans);

            // C. 拿起來 (一拿！Backtracking 恢復原狀，給其他平行時空使用)
            // - 從 cols 刪除 c (.erase(c))
            cols.erase(c);
            // - 從 posDiag 刪除 r + c
            posDiag.erase((r+c));
            // - 從 negDiag 刪除 r - c
            negDiag.erase((r-c));
            // - 將棋盤 board[r][c] 變回 '.'
            board[r][c] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // 製作一個 N x N 的空白棋盤 (全部塞滿 '.')
        vector<string> board(n, string(n, '.'));
        
        // 遊戲開始：從第 0 列 (row 0) 開始放皇后
        dfs(0, n, board, ans);
        
        return ans;
    }
};