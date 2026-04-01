class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest_l = 1;
        unordered_map<char, int> freq;
        int left = 0;
        int max_count = 0; // 視窗內「單一字元出現最多」的次數
        for (int i=0; i<s.size(); i++){
            // int r = 0;
            // int l_i = 1;
            // while (r<=k && l_i+i<s.size()){
            //     if (s[i]==s[i+l_i]){
            //         l_i++;
            //     }
            //     else{
            //         r++;
            //         if (r>k){                        
            //             break;
            //         }
            //         else{
            //             l_i++;
            //         }
            //     }
            // }
            // longest_l = max(l_i, longest_l);
            freq[s[i]]++;
            max_count = max(max_count, freq[s[i]]);
            while (i-left+1 - max_count > k){
                freq[s[left]]--;
                left++;
            }
            longest_l = max(longest_l, i-left+1);
        }
        return longest_l;

    }
};
