class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){return {};}
        int max_l = 1;
        unordered_set<char> charSet={};
        charSet.insert(s[0]);
        // int r = s.size()-1;
        int l = 0;
        for (int r=1; r<s.size(); r++){
            
            // unordered_set<char> charSet(s.begin()+l, r);
            while (charSet.find(s[r]) != charSet.end()){
                charSet.erase(s[l]);
                l++;
            }
            max_l = max(max_l, r-l+1);
            cout<<max_l<<endl;
            charSet.insert(s[r]);
        }
        return max_l;
    }
};
