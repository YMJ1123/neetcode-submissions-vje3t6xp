class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> openings = {
            {'(',0}, {'{',1}, {'[',2}
            };
        unordered_map<char, int> closings = {
            {')',0}, {'}',1}, {']',2}
            };
        stack<char> st;
        if (s.size()%2 != 0){return false;}
        for (int i = 0; i<s.size(); i++){
            if(openings.find(s[i]) != openings.end()){
                st.push(s[i]);
            }
            else{
                if (st.empty() || openings[st.top()] != closings[s[i]]){ 
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        // return true;
        return st.empty();
    }
};
