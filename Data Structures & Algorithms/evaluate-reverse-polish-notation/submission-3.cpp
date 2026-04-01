class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            string s = tokens[i];
            if(s == "+" || s=="-"||s=="/"||s=="*"){
                if(st.size() < 2) return 0;
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();
                if(s == "+"){
                    st.push(one+two);
                }else if(s=="-"){
                    st.push(two-one);
                }else if(s == "/"){
                    st.push(two/one);
                }else{
                    st.push(two*one);
                }
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
