class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int len = heights.size();

        // smaller_ids_left_arr[i]  = i 左邊「第一個嚴格小於 heights[i]」的 index
        // 若不存在，用 -1 當作虛擬邊界
        vector<int> smaller_ids_left_arr(len, -1);

        // smaller_ids_right_arr[i] = i 右邊「第一個嚴格小於 heights[i]」的 index
        // 若不存在，用 len 當作虛擬邊界
        vector<int> smaller_ids_right_arr(len, len);

        // 單調遞增 stack（存 index）
        // 會維持：heights[stack[0]] < heights[stack[1]] < ... < heights[stack.top()]
        stack<int> smaller_ids_left;
        stack<int> smaller_ids_right;

        // -----------------------------
        // 1) 找每個 i 的「左邊最近較小」(Nearest Smaller to Left)
        // -----------------------------
        for (int l = 0; l < len; l++) {
            // 當 stack top 的高度 >= 當前高度 heights[l]，它就不可能成為 l 的「較小」邊界
            // 因為我們要的是「第一個 < heights[l]」，所以 >= 的都要 pop 掉
            while (!smaller_ids_left.empty() && heights[smaller_ids_left.top()] >= heights[l]) {
                smaller_ids_left.pop();
            }

            // pop 完後：
            // - 若 stack 空，表示左邊沒有任何比它小的 -> 用 -1
            // - 否則 stack.top() 就是左邊最近且比它小的 index
            smaller_ids_left_arr[l] = smaller_ids_left.empty() ? -1 : smaller_ids_left.top();

            // 把自己放進 stack，成為後面元素的候選左邊界
            smaller_ids_left.push(l);
        }

        // -----------------------------
        // 2) 找每個 i 的「右邊最近較小」(Nearest Smaller to Right)
        //   必須從右往左掃，stack 才代表「右側的資訊」
        // -----------------------------
        for (int r = len - 1; r >= 0; r--) {
            // 同理：要找右邊第一個 < heights[r]
            // 所以右邊遇到 >= heights[r] 的柱子，都不可能當作 r 的較小邊界，通通 pop
            while (!smaller_ids_right.empty() && heights[smaller_ids_right.top()] >= heights[r]) {
                smaller_ids_right.pop();
            }

            // pop 完後：
            // - 若 stack 空：右邊沒有較小 -> 用 len
            // - 否則 top 就是右邊最近較小的 index
            smaller_ids_right_arr[r] = smaller_ids_right.empty() ? len : smaller_ids_right.top();

            // 把自己放進 stack，成為左邊元素的候選右邊界
            smaller_ids_right.push(r);
        }

        // -----------------------------
        // 3) 用左右邊界算每個 i 當「最矮高度」時能延伸的最大寬度
        // -----------------------------
        for (int i = 0; i < len; i++) {
            // i 能延伸的範圍是 (left, right) 之間，不包含 left 和 right
            // 所以寬度 = right - left - 1
            int width = smaller_ids_right_arr[i] - smaller_ids_left_arr[i] - 1;

            // 高度用 heights[i]（因為我們以 i 當作「最矮的柱子」來擴張）
            int area_i = heights[i] * width;

            ans = max(ans, area_i);
        }

        return ans;
    }
};
