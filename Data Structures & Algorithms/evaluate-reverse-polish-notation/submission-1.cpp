class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n2+n1));
            }else if(tokens[i] == "-"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n2-n1));
            }else if(tokens[i] == "*"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                st.push(to_string(n2*n1));
            }else if(tokens[i] == "/"){
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                cout<<n1<<" "<<n2<<endl;
                st.push(to_string(n2/n1));
            }else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};
