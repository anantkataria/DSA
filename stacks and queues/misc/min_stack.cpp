// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> s;
    stack<int> mini;
    MinStack() {
        while(!s.empty())
            s.pop();
        while(!mini.empty())
            mini.pop();
    }
    
    void push(int val) {
        s.push(val);
        if(mini.empty() || mini.top() > val)
            mini.push(val);
        else{
            int oldtop = mini.top();
            mini.push(oldtop);
        }
            
    }
    
    void pop() {
        s.pop();
        mini.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */