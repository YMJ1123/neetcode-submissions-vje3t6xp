class Solution {
private:
    
    // min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap; //數字越小的，優先級反而越高
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i =0; i < nums.size(); i++){
            minHeap.push(nums[i]);
            while (minHeap.size()>k){
                minHeap.pop();                
            }
        }
 
        return minHeap.top();
    }
};
