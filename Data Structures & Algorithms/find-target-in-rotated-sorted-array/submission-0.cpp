class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        int left = 0;
        int right = len - 1;
        while(left<right){
            int k = left + (right - left) / 2;
            cout<<"k = "<<k<<endl;
            if (nums[k]>nums[right]){ //交界在右半
                left = k + 1;
                cout<<"nums[k]>nums[right]"<<endl;
            }
            else {
                right = k;
            }
            
        cout<<"left = "<<left<<endl;
        cout<<"right = "<<right<<endl;
        }
        // cout<<left<<endl;
        int min_ele = nums[left]; // 迴圈結束時 left == right，指向最小值
        int min_id = left;

        int new_left = 0;
        int new_right = len-1;
        while (new_left <= new_right){ //(right - left > 1){
            int mid = (new_right - new_left)/ 2 + new_left;
            int mid_id = (min_id + mid < len) ? min_id + mid : min_id + mid - len;
            if(target==nums[mid_id]){
                return mid_id; 
            }
            else if (target > nums[mid_id]){
                // 目標在右邊，mid 已經檢查過了，所以 +1
                new_left = mid+1; 
            }
            else{
                // 目標在左邊，mid 已經檢查過了，所以 -1
                new_right = mid-1;
            }
        }

        return -1;
    }
};
