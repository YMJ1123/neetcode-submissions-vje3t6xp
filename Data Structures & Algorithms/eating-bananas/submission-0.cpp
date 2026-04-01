class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // total time = ceil(piles[0]/k)+ceil(piles[0]/k)+...+ceil(piles[len-1]/k)
        // int right = max(piles);
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        int len = piles.size();
        int mid;
        // while(right>left){
        while(right>left){
            mid = left + (right - left) / 2;
            int total_time = 0;
            for (int pile : piles){
                total_time += ceil((double)pile/(double)mid);

            }
            // 判斷是否小於等於 h
            if (total_time <= h) {
                right = mid; // 時間充裕，嘗試更慢的速度 (更小的 k)
            } else {
                left = mid + 1; // 超時了，需要更快的速度 (更大的 k)
            }
        }
        return left;
    }
};
