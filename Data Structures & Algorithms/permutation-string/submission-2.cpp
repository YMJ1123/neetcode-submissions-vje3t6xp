class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l_1 = s1.size();
        int l_2 = s2.size();
        if (l_1>l_2){ return false;}
        unordered_map<char, int> s1_freq;
        for (char c : s1) {
        s1_freq[c]++; // 直接累加，若字元不存在會自動初始化為 0
        }
        for (int i=0; i<l_2-l_1+1; i++){
            unordered_map<char, int> current_freq;
            for (int j=i; j<i+l_1; j++){
                cout<<s2[j]<<endl;
                current_freq[s2[j]]++;
            }
            if (current_freq==s1_freq){
                return true;
            }
        }
        return false;
    }
};
