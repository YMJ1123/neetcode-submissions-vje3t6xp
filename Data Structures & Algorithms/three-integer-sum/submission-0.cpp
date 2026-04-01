class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //為了讓重複的在隔壁
        int l = nums.size();
        vector<vector<int>> ans;
        for (int i=0; i<l-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue; // Skip Duplicate
            int left = i + 1;
            int right = l-1;
            int target = -nums[i];
            while (left < right){
                if (nums[left] + nums[right] > target){
                    right --;
                }
                else if (nums[left] + nums[right] < target ){
                    left ++;
                }
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        
    return ans;
    }
};
