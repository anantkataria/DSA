// https://www.interviewbit.com/problems/generate-all-parentheses/

int Solution::isValid(string A) {
    stack<char> s;
    for(int i=0; i<A.size(); i++){
        if(A[i] == '(' || A[i] == '{' || A[i] == '['){
            s.push(A[i]);
        }
        else {
            if(s.empty()){
                return 0;
            }
            else if (A[i] == ')' && s.top() == '(' || A[i] == '}' && s.top() == '{' || A[i] == ']' && s.top() == '['){
                s.pop();
            }
            else {
                return 0;
            }
        }
    }
    if(s.empty()){
        return 1;
    }
    return 0;
}
