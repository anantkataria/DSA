//problem link : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int counter = 0;
        int curr_sum = 0;
        int start = 0;
        while(counter<n){
            while(curr_sum < s){
                curr_sum += arr[counter++];
            }
            while(curr_sum > s){
                curr_sum -= arr[start++];
            }
            if(curr_sum == s){
                return vector<int>{start+1, counter};
            }
        }
        
        return vector<int>{-1};
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends