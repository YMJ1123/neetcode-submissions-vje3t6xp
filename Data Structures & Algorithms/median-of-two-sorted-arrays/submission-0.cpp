class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total_len = len1 + len2;
        int min_len = min(len1, len2);
        // vector<int> A, B;
        // if (min_len == len1){
        //     & A = nums1;
        //     & B = nums2;
        // }else{
        //     & B = nums1;
        //     & A = nums2;
        // }

        // 如果 nums1 比 nums2 長，就交換它們再呼叫一次
        // 這樣可以保證我們只對短的做二分搜尋，效率更高且避免 j 越界
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int totalleft = (total_len+1)/2;

        // 二分搜尋的範圍：在 nums1 (短陣列) 上找切點
        int left = 0;
        int right = len1;

        while (left <= right) {
            // i 是 nums1 的切點 (也就是 nums1 左邊有幾個元素)
            int i = left + (right - left) / 2;
            // j 是 nums2 的切點 (剩下的都由 nums2 提供)
            int j = totalleft - i;

            // 處理邊界值：
            // 如果切在最左邊 (i=0)，左邊沒東西，設為負無窮大
            // 如果切在最右邊 (i=m)，右邊沒東西，設為正無窮大
            int nums1LeftMax = (i == 0) ? -1e6 : nums1[i - 1];
            int nums1RightMin = (i == len1) ? 1e6 : nums1[i];
            
            int nums2LeftMax = (j == 0) ? -1e6 : nums2[j - 1];
            int nums2RightMin = (j == len2) ? 1e6 : nums2[j];
            // 檢查是否分割正確 (交叉比較)
            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                if (total_len%2 == 0){
                    // 偶數個：左邊最大 和 右邊最小 的平均
                    return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
                }else{
                    // 奇數個：因為我們讓左邊多一個，所以答案就是左邊最大的那個
                    return max(nums1LeftMax, nums2LeftMax);
                }
            }
            else if (nums1LeftMax > nums2RightMin){
                // nums1 左邊太大了，切點要往左移
                right = i - 1;
            }else {
                // nums2 左邊太大了 (或是 nums1 右邊太小)，nums1 切點要往右移，多拿一點
                left = i + 1;
            }
        }
        
        return 0.0; // 理論上不會執行到這裡
    

    }
};
