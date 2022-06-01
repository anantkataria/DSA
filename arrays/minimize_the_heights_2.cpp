//https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        
        int min_here;
        int max_here;
        int ans = arr[n-1]-arr[0];//This is the case when we add k/ subtract k in all elements
        
        for(int i=0; i<n; i++){
            if(arr[i] < k)
                continue;
            
            min_here = min(arr[0]+k, arr[i]-k);
            max_here = max(arr[i-1]+k, arr[n-1]-k);
            
            ans = min(ans, max_here-min_here);
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