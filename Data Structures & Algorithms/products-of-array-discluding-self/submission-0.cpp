class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> ans(l, 1);
        for (int i = 1; i<l; i++){
            ans[i] = ans[i-1] * nums[i-1];

        }
        int suffix = 1;
        for (int j = l - 1; j >= 0; j--) {
            ans[j] *= suffix;
            suffix *= nums[j];
        }
        return ans;
    }
};
