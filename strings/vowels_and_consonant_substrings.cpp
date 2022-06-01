//https://www.interviewbit.com/problems/vowel-and-consonant-substrings/

int Solution::solve(string A) {
    int n = A.size();
    if(n <= 1)
        return 0;

    int vowelCount = 0;
    int consCount = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
            vowelCount++;
            ans += consCount;
        }
        else{
            consCount++;
            ans += vowelCount;
        }
    }

    return ans%(1000000000+7);
}
