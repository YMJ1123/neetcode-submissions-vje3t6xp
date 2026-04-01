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
        dfs(target - nums[index], index + 1, current, nums, ans);
        // 4. 選擇 B：「不要」這個數字 (Backtracking 恢復原狀)
        current.pop_back();
        // dfs(target, index + 1, current, nums, ans); 
        // 跳過重複的
        int next_index = index + 1;
        while (next_index < nums.size() && nums[next_index] == nums[index]) {
            next_index++;
        }

        dfs(target, next_index, current, nums, ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        // sort 才能讓相同的元素排一起
        sort(candidates.begin(), candidates.end());

        dfs(target, 0, current, candidates, ans);

        return ans;
    }
};
