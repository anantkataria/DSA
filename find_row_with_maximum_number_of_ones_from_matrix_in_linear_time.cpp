// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int one_min_index = INT_MAX;
	    int ans = -1;
	    for(int i=0; i<m; i++){
	        if(arr[0][i] == 1){
	            one_min_index = i;
	            ans = 0;
	            break;
	        }
	    }
	    
	    for(int i=1; i<n; i++){
	        int j = one_min_index==INT_MAX? m-1: one_min_index;
	        while(j>=0 && arr[i][j] == 1){
	            j--;
	        }
	        if(j+1 < one_min_index && arr[i][j+1] == 1 && j+1<m){//have put some extra conditions here for edge cases
	            one_min_index = j+1;
	            ans = i;
	        }
	    }
	    
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends