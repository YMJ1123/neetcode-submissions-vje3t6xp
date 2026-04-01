class MinStack {
private:
    stack<int> s;
    stack<int> min_s;
public:
    MinStack() {
        // stack<int> s;
        // stack<int> min_s;
    }
    
    void push(int val) {
        s.push(val);
        if (!min_s.empty()){
            int new_min = min(min_s.top(), val);
            min_s.push(new_min);
        }
        else{
            min_s.push(val);
        }
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};
