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
                // 目標在右邊，mid 已經檢查過了，所以 +1
                left = mid+1; 
            }
            else{
                // 目標在左邊，mid 已經檢查過了，所以 -1
                right = mid-1;
            }
        }
        return -1;
    }
};
