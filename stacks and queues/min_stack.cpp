//https://www.interviewbit.com/problems/min-stack/

//There is a slight optimization possible over this. Think of it.

stack<int> st, temp;

MinStack::MinStack() {
    while(!st.empty()){
        st.pop();
    }
    while(!temp.empty()){
        temp.pop();
    }
}

void MinStack::push(int x) {
    st.push(x);
    if(temp.empty()){
        temp.push(x);
    }
    else{
        temp.push(min(temp.top(), x));
    }
}

void MinStack::pop() {
    if(!st.empty()){
        st.pop();
    }
    if(!temp.empty()){
        temp.pop();
    }
}

int MinStack::top() {
    if(!st.empty()){
        return st.top();
    }
    return -1;
}

int MinStack::getMin() {
    if(!temp.empty()){
        return temp.top();
    }
    return -1;
}

