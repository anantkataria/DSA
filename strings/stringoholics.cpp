//https://www.interviewbit.com/problems/stringoholics/

//first find length of string considering recurring substring
//next loop from n = 1 to 2*len -1 and check if n(n+1)/2 modulo len equals zero. 
//take lcm of this value with previous ans.
//at the end return lcm

int findrecsubstringlength(string a){
    vector<int> lps(a.size());
    lps[0] = 0;
    int i = 1;
    int prevlps = 0;
    
    while(i<a.size()){
        if(a[i] == a[prevlps]){
            lps[i] = prevlps + 1;
            prevlps++;
            i++;
        }
        else {
            if(prevlps != 0){
                prevlps = lps[prevlps-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    if(a.size() % (a.size() - lps[a.size()-1]) == 0){
        return (a.size() - lps[a.size()-1]);
    }
    return a.size();
}

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    if(b < a){
        int temp = a;
        a = b;
        b = temp;
    }
    return a*b/gcd(a, b);
}

int Solution::solve(vector<string> &A) {
    int ans = 1;
    for(int i=0; i<A.size(); i++){
        int len = findrecsubstringlength(A[i]);
        for(int j = 1; j<=(2*len)-1; j++){
            if((j*(j+1)/2)%len == 0){
                ans = lcm(ans, j);
                break;
            }
        }
    }
    
    return ans;
}
