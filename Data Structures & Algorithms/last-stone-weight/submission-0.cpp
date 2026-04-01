class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        // 把所有石頭丟進 Heap 裡
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if(y>x){
                maxHeap.push(y-x);
            }
        }

        // 最後判斷：如果 Heap 空了回傳 0，否則回傳剩下的那顆石頭
        if (maxHeap.empty()) {
            return 0;
        } else {
            return maxHeap.top();
        }
    }
};
