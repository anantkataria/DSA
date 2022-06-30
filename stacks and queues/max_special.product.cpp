//https://www.interviewbit.com/problems/maxspprod/
//https://www.geeksforgeeks.org/maximum-product-of-indexes-of-next-greater-on-left-and-right/
//https://leetcode.com/problems/next-greater-element-i/


long long max(long long a, long long b){
    return (a > b) ? a : b;
}

vector<int> findNextGreaterElementIndex(vector<int>& A){
    stack<int> s;
    vector<int> nextGreaterElementI(A.size(), 0);
    for(int i=0; i<A.size(); i++){
        while(!s.empty() && A[s.top()] < A[i]){
            nextGreaterElementI[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return nextGreaterElementI;
}

vector<int> findPreviousGreaterElementIndex(vector<int>& A){
    stack<int> s;
    vector<int> previousGreaterElementI(A.size(), 0);
    for(int i=A.size()-1; i>=0; i--){
        while(!s.empty() && A[s.top()] < A[i]){
            previousGreaterElementI[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return previousGreaterElementI;
}

long long getmaxmultiplication(vector<int> lsa, vector<int> rsa) {
    long long ans = 0l;
    for(int i=0; i<lsa.size(); i++){
        ans = max(ans, lsa[i]*1ll*rsa[i]);
    }
    return ans;
}

int Solution::maxSpecialProduct(vector<int> &A) {
    vector<int> rsa = findNextGreaterElementIndex(A);
    vector<int> lsa = findPreviousGreaterElementIndex(A);
    return getmaxmultiplication(lsa, rsa)%(1000000007);
}
