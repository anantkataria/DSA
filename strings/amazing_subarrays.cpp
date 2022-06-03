//https://www.interviewbit.com/problems/amazing-subarrays/

int Solution::solve(string A) {
    int n = A.size();
    int ans=0;
    for(int i=0; i<n; i++){
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U'){
            ans += n-i;
        }
    }

    return ans%10003;
}
