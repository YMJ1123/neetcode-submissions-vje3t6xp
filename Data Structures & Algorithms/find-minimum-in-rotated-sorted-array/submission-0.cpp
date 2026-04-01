class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left<right){
            int mid = left + (right - left) / 2;
            cout<<"mid = "<<mid<<endl;
            if (nums[mid]>nums[right]){ //交界在右半
                left = mid + 1;
                cout<<"nums[mid]>nums[right]"<<endl;
            }
            else {
                right = mid;
            }
            
        cout<<"left = "<<left<<endl;
        cout<<"right = "<<right<<endl;
        }
        // cout<<left<<endl;
        return nums[left]; // 迴圈結束時 left == right，指向最小值
    }
};
