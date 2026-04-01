class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 雙向佇列(double-ended queue)
        deque<int> d;
        // d.push_back(0);
        // for (int n=0; n<k; n++){
        //     d.push_back(n);
        // }
        vector<int> ans;
        for (int i=0; i<nums.size(); i++){
            while(!d.empty() && d.front() <= i-k){
                // 視窗範圍是 [i−k+1,i]
                d.pop_front();
            }
            while(!d.empty() && nums[d.back()] <= nums[i]){ //!d.empty() 要放前面，不然可能 UB
                d.pop_back();
            }
            d.push_back(i);
            if (i>=k-1){
                ans.push_back(nums[d.front()]);
                }
       }
       return ans;

    }
};
