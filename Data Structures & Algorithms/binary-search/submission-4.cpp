class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int mid;
        int left = 0;
        int right = len-1;
        while (left <= right){ //(right - left > 1){
            // cout<<"left = "<<left<<endl;
            // cout<<"right = "<<right<<endl;
            mid = (right - left)/ 2 + left;
            if(target==nums[mid]){
                return mid; 
            }
            else if (target > nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return -1;
    }
};
