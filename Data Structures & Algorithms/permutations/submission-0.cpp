class Solution {
private: 
    void dfs(vector<bool>& used, vector<int>& current, vector<int>& nums, vector<vector<int>>& ans){
        if (current.size()==nums.size()){
            ans.push_back(current);
            return;
        }

        // 排列的精髓：每次都從 0 開始看全部的數字
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]){
                continue;
            }
            // 選擇「要」這個數字
            used[i] = true;
            current.push_back(nums[i]);
            dfs(used, current, nums, ans);

            // 選擇「不要」這個數字
            current.pop_back();
            used[i] = false;

        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        vector<bool> used(nums.size(), false);

        dfs(used, current, nums, ans);
        
        return ans;
    }
};
