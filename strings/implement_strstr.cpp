//https://www.interviewbit.com/problems/implement-strstr/

int Solution::strStr(const string A, const string B) {
    //B is needle
    //A is haystack
    if(A.empty()){
        return -1;
    }
    if(B.empty()){
        return -1;
    }

    int n = B.size(); //needle length
    int m = A.size(); // haystack length
    for(int i=0; i<m; i++){
        if(A[i] == B[0]){
            int count = 0;
            int haycount = i;
            while(count < n && haycount < m){
                if(A[haycount] == B[count]){
                    count++;
                    haycount++;
                }else{
                    break;
                }
            }
            if(count == n){
                return i;
            }
        }
    }
    return -1;
}
