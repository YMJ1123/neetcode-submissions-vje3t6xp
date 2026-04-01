class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, box[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int d = ch - '1';           // 0..8
                int mask = 1 << d;
                int b = (r / 3) * 3 + (c / 3);

                if (row[r] & mask) return false;
                if (col[c] & mask) return false;
                if (box[b] & mask) return false;

                row[r] |= mask;
                col[c] |= mask;
                box[b] |= mask;
            }
        }
        return true;
    }
};