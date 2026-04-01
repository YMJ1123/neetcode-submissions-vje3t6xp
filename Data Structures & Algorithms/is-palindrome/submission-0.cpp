class Solution {
public:
    bool isPalindrome(string s) {
        // 使用 erase-remove idiom
        // 判斷邏輯：如果是標點 (ispunct) 或 空格 (isspace)，則移除
        s.erase(remove_if(s.begin(), s.end(), 
        [](unsigned char c) { 
            return ispunct(c) || isspace(c); 
        }), 
        s.end());
        // cout>>s>>endl();

        int left = 0;
        int right = s.length() - 1;
        while (left<right){
            if (tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;


    }
};
