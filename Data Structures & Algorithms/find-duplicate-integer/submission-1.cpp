class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = nums.size();
        int n = l-1;
        for (int i = 0; i<l; i++){
            // since nums is in the range [1, n]
            if (nums[abs(nums[i])-1] < 0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1] *= -1;
            }

        }
    }
};
