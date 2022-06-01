//https://www.interviewbit.com/problems/remove-consecutive-characters/

string Solution::solve(string A, int B) {
    int n = A.size();
    if(n <= 1){
        return A;
    }

    string ans = "";
    char curr = A[0];
    int count = 1;

    int i=1;
    while(i < n){
        while(A[i] == curr){
            count++;
            i++;
        }

        count = count%B;
        while(count > 0){
            ans+=A[i-1];
            count--;
        }
        if(i < n){
            count = 1;
            curr = A[i];
            i++;
        }
    }

    if(count > 0){
        count = count%B;
        while(count > 0){
            ans+=A[i-1];
            count--;
        }
    }
    return ans;
}
