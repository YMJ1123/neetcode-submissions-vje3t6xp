class KthLargest {
private:
    int k;
    // min-heap
    priority_queue<int, vector<int>, greater<int>> minHeap; //數字越小的，優先級反而越高
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i =0; i < nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        while(minHeap.size() > k){
            minHeap.pop();
            
        }
        return minHeap.top();
    }
};
