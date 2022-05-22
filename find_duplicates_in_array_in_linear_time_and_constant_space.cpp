// Traverse the given array from start to end.
// For every element in the array increment the arr[i]%n‘th element by n.
// Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index
// This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater than n only if a value “i” has appeared more than once.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        for(int i=0; i<n; i++){
            arr[arr[i]%n] += n;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(arr[i] >= n*2)
                ans.push_back(i);
        }
        
        if(ans.empty())
            ans.push_back(-1);
            
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends