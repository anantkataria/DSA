// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        // Your code here
        unordered_map<int, int> m;
        
        int max_len = 0;
        int curr_sum = 0;
        for(int i=0; i<n; i++){
            curr_sum += (arr[i] == 0)?-1:1;
            
            if(curr_sum == 0){
                max_len = max(i+1, max_len);
            }
            
            if(m.find(curr_sum)!=m.end()){
                max_len = max(max_len, i-m[curr_sum]);
            }
            else{
                m[curr_sum] = i;
            }
        }
        
        return max_len;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends