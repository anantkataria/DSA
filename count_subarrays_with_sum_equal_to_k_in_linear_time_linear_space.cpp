// Efficient Solution : An efficient solution is while traversing the array, storing sum so far in currsum. Also, maintain the count of different values of currsum in a map. If the value of currsum is equal to the desired sum at any instance increment count of subarrays by one. The value of currsum exceeds the desired sum by currsum – sum. If this value is removed from currsum then the desired sum can be obtained. From the map, find the number of subarrays previously found having sum equal to currsum-sum. Excluding all those subarrays from the current subarray, gives new subarrays having the desired sum. So increase count by the number of such subarrays. Note that when currsum is equal to the desired sum then also check the number of subarrays previously having a sum equal to 0. Excluding those subarrays from the current subarray gives new subarrays having the desired sum. Increase the count by the number of subarrays having sum 0 in that case.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        unordered_map<int, int> m;
        int curr_sum = 0;
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            curr_sum += arr[i];
            
            if(curr_sum == k){
                ans++;
            }
            if(m.find(curr_sum-k) != m.end()){
                ans += m[curr_sum-k];
            }
            
            m[curr_sum]++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends