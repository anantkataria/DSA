//https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        
        int mi = arr[0]-k, ma = max(arr[n-1]-k, arr[0]+k);
        int ans = min(arr[n-1]-arr[0], ma-mi);
        
        for(int i=1; i<n; i++){
            mi = min(arr[0]+k, arr[i]-k);
            ma = max(arr[n-1]-k, arr[i-1]+k);
            ans = min(ans, ma-mi);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends    