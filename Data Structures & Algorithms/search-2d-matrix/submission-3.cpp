class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t row_count = matrix.size();
        size_t col_count = matrix[0].size();
        int full_len = row_count*col_count;
        int mid;
        int left = 0;
        int right = full_len-1;
        while (left <= right){
            mid = (right - left)/ 2 + left;
            int mid_row = mid/col_count;
            int mid_col = mid%col_count;
            if(target == matrix[mid_row][mid_col]){
                return true; 
            }
            else if (target > matrix[mid_row][mid_col]){
                // 目標在右邊，mid 已經檢查過了，所以 +1
                left = mid+1; 
            }
            else{
                // 目標在左邊，mid 已經檢查過了，所以 -1
                right = mid-1;
            }
            
        }
        return false;
    }
};
