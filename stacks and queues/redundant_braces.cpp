// https://www.codingninjas.com/codestudio/problem-details/redundant-brackets_975473

int Solution::braces(string A) {
    stack<char> s;
    for(int i=0; i<A.size(); i++){
        if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/' || A[i] == '('){
            s.push(A[i]);
        }
        else if(A[i] == ')'){
            bool flag = true;
            while(!s.empty() && s.top()!='('){
                if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                    flag = false;
                s.pop();
            }
            s.pop();
            if(flag)
                return 1;
        }
    }
    return 0;
}
