int Solution::solve(string A) {
    string temp = A;
    reverse(temp.begin(), temp.end());
    string x = temp + "$" + A;
    
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


// xxbab$babxx babxxbab -> append in front

// babxx$xxbab xxbabxx -> append in back