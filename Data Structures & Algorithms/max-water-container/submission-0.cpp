class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = heights.size();
        int i = 0;
        int j = l-1;
        int max_vol = 0; 
        while(i<j){
            int min_h = min(heights[i], heights[j]);
            max_vol = max((j - i) * min_h, max_vol);
            if (min_h == heights[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return max_vol;
    }
};
