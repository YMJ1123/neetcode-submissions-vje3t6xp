class Solution {
public:
    string minWindow(string s, string t) {
        int l_s = s.size();
        int l_t = t.size();
        if (l_s<l_t){return "";}
        string ans = "";
        unordered_map<char, int> t_freq;
        int required_count = l_t;
        int min_l = 1000;
        for (char c : t){
            t_freq[c]++;
        }
        int left = 0;
        for (int r=0; r<l_s; r++){
            unordered_map<char, int> current_freq;
            char current_char = s[r];
            if (t_freq.find(s[r])!=t_freq.end()){
                t_freq[s[r]]--;
                if (t_freq[s[r]]>=0){
                    required_count--;
                }
            }
            while (required_count == 0){
                if ((r - left + 1)<min_l){
                    min_l = r - left + 1;
                    ans = s.substr(left, r - left + 1);
                }
                if (t_freq.find(s[left])!=t_freq.end()){
                    t_freq[s[left]]++;
                    if (t_freq[s[left]]>0){
                        //失去一個必要字元
                        required_count++;
                    }
                }
                left++;
            }
        }
        return ans;

    }
};
