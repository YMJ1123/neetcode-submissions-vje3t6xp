class Solution {
// private:
    // priority_queue<int>
public:
    int getDistance(vector<int> pt){
        return pt[0] * pt[0] + pt[1] * pt[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for (vector<int> pt : points){
            int distSquare = getDistance(pt);
            maxHeap.push({distSquare,pt});

            if (maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            // maxHeap.top().second 就可以拿出我們剛剛存進去的座標！
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
