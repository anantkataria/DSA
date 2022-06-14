//https://www.interviewbit.com/problems/convert-to-palindrome/

bool isP(string A, int l, int r){
    while(l <= r){
        if(A[l] != A[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int Solution::solve(string A) {
    // abcxcbca aabxcbaa aaaabbcx
    if(A.size()<=1)
        return 1;
        
    int l = 0;
    int r = A.size()-1;
    
    while(l <= r && A[l] == A[r]){
        l++;
        r--;
    }
    
    return (isP(A, l+1, r) || isP(A, l, r-1));
}
