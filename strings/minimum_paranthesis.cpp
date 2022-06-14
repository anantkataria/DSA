//https://www.interviewbit.com/problems/minimum-parantheses/

int Solution::solve(string A) {
    int balance = 0;
    int ans = 0;
    for(int i=0; i<A.size(); i++){
        balance += A[i]=='('?1:-1;
        if(balance == -1){
            ans++;
            balance++;
        }
    }
    
    return ans+balance;
}
