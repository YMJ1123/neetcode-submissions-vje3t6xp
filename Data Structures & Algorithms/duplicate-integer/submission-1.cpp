class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int l = nums.size();
        // bool b = true;
        
        // int prev = nums[0];
        for (int i=0;i<l;i++){
            for (int j=i+1; j<l;j++){
                int prev = nums[i];
                if(prev==nums[j]){
                    return true;            
                    }
            }
            
            // prev=nums[i];

        }
        return false;
    }
};