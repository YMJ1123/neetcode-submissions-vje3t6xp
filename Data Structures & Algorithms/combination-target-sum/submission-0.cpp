class Solution {
private:
    void dfs(int target, int index, vector<int>& current, vector<int>& nums, vector<vector<int>>& ans) {
        // target 用扣的
        if (target == 0){
            ans.push_back(current);
            return;
        }
        // 2. 終止條件 B：血量扣過頭 (變負數)，或者走到陣列盡頭了，這條路失敗
        if (target < 0 || index >= nums.size()) {
            return;
        }

        // 3. 選擇 A：「要」這個數字
        current.push_back(nums[index]);
        dfs(target - nums[index], index, current, nums, ans);
        // 4. 選擇 B：「不要」這個數字 (Backtracking 恢復原狀)
        current.pop_back();
        dfs(target, index + 1, current, nums, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        
        dfs(target, 0, current, nums, ans);

        return ans;
    }
};
