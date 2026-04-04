#include <vector>

using namespace std;

class Solution {
private:
    // 特種部隊出動：把相連的陸地全部炸成水 ('0')
        void dfs(vector<vector<char>>& grid, int r, int c) {
                // 1. 邊界檢查與終止條件
                        // 如果越界了，或者踩到的根本是水 ('0')，就直接回頭
                                if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
                                            return;
                                                    }

                                                            // 2. 標記走過：擊沉這塊陸地！
                                                                    grid[r][c] = '0';

                                                                            // 3. 往四個方向繼續擴散
                                                                                    dfs(grid, r + 1, c); // 下
                                                                                            dfs(grid, r - 1, c); // 上
                                                                                                    dfs(grid, r, c + 1); // 右
                                                                                                            dfs(grid, r, c - 1); // 左
                                                                                                                }

                                                                                                                public:
                                                                                                                    int numIslands(vector<vector<char>>& grid) {
                                                                                                                            if (grid.empty()) return 0;
                                                                                                                                    
                                                                                                                                            int islands = 0;
                                                                                                                                                    int rows = grid.size();
                                                                                                                                                            int cols = grid[0].size();

                                                                                                                                                                    // 開著直升機巡邏每一個格子
                                                                                                                                                                            for (int r = 0; r < rows; r++) {
                                                                                                                                                                                        for (int c = 0; c < cols; c++) {
                                                                                                                                                                                                        // 如果發現陸地！
                                                                                                                                                                                                                        if (grid[r][c] == '1') {
                                                                                                                                                                                                                                            islands++;          // 計數器 + 1
                                                                                                                                                                                                                                                                dfs(grid, r, c);    // 派出特種部隊把這整座島擊沉
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                            return islands;
                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                };
                                                                                                                                                                                                                                                                                                                
