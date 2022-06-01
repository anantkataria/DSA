// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> multiplication = {1};
        
        int curr_mul = 1;
        int carry = 0;
        for(int i=2; i<=N; i++){
            for(int x=0; x<multiplication.size(); x++){
                curr_mul = multiplication[x]*i + carry;
                multiplication[x] = curr_mul%10;
                curr_mul /= 10;
                carry = curr_mul;
            }
            while(carry>0){
                multiplication.push_back(carry%10);
                carry/=10;
            }
        }
        
        reverse(multiplication.begin(), multiplication.end());
        return multiplication;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends