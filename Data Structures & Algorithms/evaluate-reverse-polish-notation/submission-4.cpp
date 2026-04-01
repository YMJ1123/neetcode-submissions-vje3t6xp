class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> int_s;
        for (int i = 0; i< tokens.size(); i++){
            string c = tokens[i];
            // use stoi()
            if (!isOperator(c)){
                int n = stoi(c);
                int_s.push(n);
            }
            else{
                int n1 = int_s.top();
                int_s.pop();
                int n2 = int_s.top();
                int_s.pop();
                
                //compute
                int current_r = perform_operation(n2, n1, c[0]);
                //push the result to the stack
                int_s.push(current_r);
            }
        }
        return int_s.top();
    }

    bool isOperator(string s){
        cout<<s<<endl;
        if (s.size()>1){return false;}
        else{
            char c = s[0];
            if (c=='+'|| c=='-' || c=='*' || c=='/'){
                return true;
            }
        }
        
        return false;
    }
    int perform_operation(int operand1, int operand2, char op) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                // It's good practice to add a check for division by zero
                if (operand2 == 0) {
                    throw std::runtime_error("Division by zero error");
                }
                return operand1 / operand2;
            default:
                // Handle invalid operators
                throw std::runtime_error("Invalid operator");
        }
    }
};
