class Solution {
private:
    // 建立手機按鍵的對應表 (把 0 和 1 留空，這樣 index 就能完美對應數字)
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(int index, const string& digits, string& current, vector<string>& ans) {
        if (index == digits.length()){
            ans.push_back(current);
            return ;
        }
        int digit = digits[index] - '0';
        string letters = pad[digit];

        // 3. 嘗試把每一個字母放進去 (一放一拿！)
        for (char c : letters) {
            current.push_back(c);

            // 往下走：帶著更新後的背包，去處理下一個數字 (index + 1)
            dfs(index+1, digits, current, ans);

            // 拿出來：(Backtracking 恢復原狀，準備嘗試下一個字母)
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string current;
        int index = 0; 
        if (digits.empty()) { //防呆：如果輸入是空的，直接回傳空陣列 []
            return ans;
        }
        dfs(index, digits, current, ans);
        
        return ans;
    }
};
