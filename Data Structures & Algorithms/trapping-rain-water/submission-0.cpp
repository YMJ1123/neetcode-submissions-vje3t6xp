class Solution {
public:
    int trap(vector<int>& height) {
        // calculate the i_th trapped water volume 
        // initialize l = i-1, r = i+1
        // if h[l] < h[r] 
        // when r>=l, add min(h[r], h[l])*
        int length = height.size();
        int ans = 0;
        for (int i=1; i<length-1; i++){
            int right_max = 0;
            int left_max = 0;
            for (int r = i+1; r<length; r++){
                right_max = max(height[r], right_max);
            }
            for (int l = i-1; l>=0; l--){
                left_max = max(height[l], left_max);
            }
            // if (l<0 || r>length-1){continue;}
            // int right_max = height[r];
            // int left_max = height[l];
            ans += max(min(left_max, right_max) - height[i], 0);
            cout<<max(min(left_max, right_max) - height[i], 0)<< endl;

        }
        return ans;
    }
};
