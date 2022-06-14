int Solution::solve(string A) {
    string temp = A;
    reverse(temp.begin(), temp.end());
    string x = A + "$" + temp;
    
    vector<int> lps(x.size());
    lps[0] = 0;
    int i=1;
    int j=0;
    
    while(i<x.size()){
        if(x[i] == x[j]){
            lps[i] = j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return A.size()-lps[x.size()-1];
}
