class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = numbers.size();
        int left = 0;
        int right = l-1;
        while (left < right){
            if (numbers[left] + numbers[right] > target){
                right --;
            }
            else if (numbers[left] + numbers[right] < target ){
                left ++;
            }
            else{
                return {left+1, right+1};
            }
        }
        return {};
    }
};
