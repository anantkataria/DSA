//https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    string x = A[0];
    for(int i=1; i<n; i++){
        string temp = "";
        for(int j=0; j<A[i].size(); j++){
            if(x[j] == A[i][j]){
                temp += x[j];
            }else{
                break;
            }
        }
        x = temp;
    }

    return x;
}
