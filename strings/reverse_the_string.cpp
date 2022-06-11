//https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
    string ans = "";
    string temp = "";
    for(int i=0; i<A.size(); i++){
        if(A[i] == ' '){
            if(!temp.empty()){
                ans = temp + " " + ans;
                temp =  "";
            }
        }
        else {
            temp += A[i];
        }
    }
    
    if(!temp.empty()){
        ans = temp + " " + ans;
    }
    
    
    //last character is space then we need to correct it
    if(ans[ans.size()-1] == ' '){
        temp = "";
        for(int i=0; i<ans.size()-1; i++){
            temp += ans[i];
        }
        return temp;
    }
    
    return ans;
}