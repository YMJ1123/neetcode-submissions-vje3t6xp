class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // add num into maxHeap
        maxHeap.push(num);
        // keep the element of maxHeap smaller than minHeap
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // Keep the size balance (maxHeap with one more if the whole size is an odd number)
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // if the whole size is an odd number
        if (maxHeap.size() > minHeap.size()) {
            return double(maxHeap.top());
        }
        // even
        else{
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};
