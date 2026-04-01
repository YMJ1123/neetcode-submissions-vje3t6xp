class Solution {
public:
    bool isAnagram(string s, string t) {
        int l_s = s.size();
        int l_t = t.size();
        if (l_s != l_t ){return false;}
        unordered_map<char, int> counts;
        for (char c : s){
            counts[c]++;
        }

        for (char c2: t){
            if (counts.find(c2) == counts.end()||counts[c2]==0){
                return false;
            }
            counts[c2]--;
        }
        return true;



    }
};
