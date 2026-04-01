class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        vector<int> ans;
        unordered_map<int, int> myMap; // diff as key, index as value
        for (int i=0; i<l; i++){
            int diff = target - nums[i];
            if (myMap.find(diff) != myMap.end()){
                ans = {myMap[diff], i};
                return ans;
            }
            else{
                myMap.emplace(nums[i], i);
            }
        }
        return {};
    }
};
