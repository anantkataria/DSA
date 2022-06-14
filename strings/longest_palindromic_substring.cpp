//https://www.interviewbit.com/problems/longest-palindromic-substring/

string Solution::longestPalindrome(string A) {
    int n = A.size();
    int i, j;
    int max = 1;
    int max_i = 0;
    int max_j = 0;
    for(int k=0; k<n-1; k++){
        i = k; j = k+1;
        while(i>=0 && j<n && A[i]==A[j]){
            if(j-i+1 > max){
                max = j-i+1;
                max_i = i;
                max_j = j;
            }
            i--; j++;
        }
    }
    for(int k=1; k<n-1; k++){
        i = k-1; j = k+1;
        while(i>=0 && j<n && A[i]==A[j]){
            if(j-i+1 > max){
                max = j-i+1;
                max_i = i;
                max_j = j;
            }
            i--;
            j++;
        }
    }
    return A.substr(max_i, max_j-max_i+1);
}


//LPS method
//take substring one by one by removing characters from the front of the string
//then make a new string by appending a special character in the middle and the mirror string on the right side
//now run longest prefix suffix code on this processed string to get a palindromic string for current substring
//do this for all substrings
//return max
//we only decrement letters from front side and not from the back side because
//it will produce the same result. Check this with some example testcase

// int lps(string a){
//     vector<int> lps(a.size());
//     lps[0] = 0;
//     int i=1;
//     int j=0;
//     while(i<a.size()){
//         if(a[i] == a[j]){
//             lps[i] = j+1;
//             j++;
//             i++;
//         }
//         else {
//             if(j!=0){
//                 j = lps[j-1];
//             }
//             else {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
    
//     return lps[a.size()-1];
// }

// string Solution::longestPalindrome(string A) {
//     if(A.size() == 1)
//         return A;
//     int maxx = 0;
//     string ans = "";
//     for(int i=0; i<A.size()-1; i++){
//         string sub = A.substr(i);
//         string temp = sub;
//         reverse(temp.begin(), temp.end());
//         string anal = sub + "$" + temp;
//         int r = lps(anal);
//         if(r > maxx){
//             maxx = r;
//             ans = A.substr(i, r);
//         }
//     }
    
//     return ans;
// }

// bcxxzxxab