class Solution {
private:
    // index: 目前走到 nums 的第幾個數字面前
    // current: 目前背包裡裝了哪些數字
    // ans: 收集所有結果的最終大陣列
    void dfs(int index, vector<int>& current, vector<int>& nums, vector<vector<int>>& ans) {
        // 1. 終止條件：如果所有的數字都做過決定了 (走到陣列盡頭)
        if (index >= nums.size()) {
            ans.push_back(current); // 把背包裡的組合存進答案裡
            return;                 // 結束這條路線
        }

        // 2. 選擇 A：「要」這個數字
        current.push_back(nums[index]);       // 放進背包
        dfs(index + 1, current, nums, ans);   // 帶著它繼續往下一個數字前進

        // 3. 選擇 B：「不要」這個數字 (這就是 Backtracking 反悔的精髓！)
        current.pop_back();                   // 🔑 把剛剛放進去的數字拿出來，恢復原狀
        dfs(index + 1, current, nums, ans);   // 帶著沒裝這個數字的背包，繼續往下一個數字前進
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        dfs(0, current,nums, ans);
        return ans;
    }
};
