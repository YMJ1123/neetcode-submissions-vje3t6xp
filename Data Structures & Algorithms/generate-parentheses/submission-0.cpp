#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void dfs(int open_count, int close_count, int n, string& current, vector<string>& ans) {
            // 1. 終止條件：括號都放滿了
                    if (open_count == n && close_count == n) {
                                ans.push_back(current);
                                            return;
                                                    }

                                                            // 2. 選擇放左括號 '('
                                                                    if (open_count < n) {
                                                                                current.push_back('(');
                                                                                            dfs(open_count + 1, close_count, n, current, ans);
                                                                                                        current.pop_back(); // Backtracking 恢復原狀
                                                                                                                }

                                                                                                                        // 3. 選擇放右括號 ')' (條件：右邊數量必須小於左邊)
                                                                                                                                if (close_count < open_count) {
                                                                                                                                            current.push_back(')');
                                                                                                                                                        dfs(open_count, close_count + 1, n, current, ans);
                                                                                                                                                                    current.pop_back(); // Backtracking 恢復原狀
                                                                                                                                                                            }
                                                                                                                                                                                }

                                                                                                                                                                                public:
                                                                                                                                                                                    vector<string> generateParenthesis(int n) {
                                                                                                                                                                                            vector<string> ans;
                                                                                                                                                                                                    string current = "";
                                                                                                                                                                                                            
                                                                                                                                                                                                                    dfs(0, 0, n, current, ans);
                                                                                                                                                                                                                            
                                                                                                                                                                                                                                    return ans;
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        };
