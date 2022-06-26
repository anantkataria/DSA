// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    stack <string> st;
    string res;
    int n=A.size();
    for(int i=0; i<n ; i++){
        string dir;
        while(A[i]!='/' and i<n){
            dir.push_back(A[i++]);
        }
        if(dir==".") continue;
        else if(dir==".."){
            if(!st.empty())st.pop();
        }
        else if(dir.size()) st.push(dir);
    }
    stack <string> st2;
    while(!st.empty()){
        st2.push(st.top());
        st.pop();
    }
    while(!st2.empty()){
        res.push_back('/');
        res+=st2.top();
        st2.pop();
    }
    if(res.size()==0) return "/";
    return res;
}