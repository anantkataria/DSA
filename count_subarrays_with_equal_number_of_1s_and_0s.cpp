// Approach: Following are the steps: 

// Consider all 0’s in arr[] as -1.
// Create a hash table that holds the count of each sum[i] value, where sum[i] = sum(arr[0]+..+arr[i]), for i = 0 to n-1.
// Now start calculating the cumulative sum and then we get an incremental count of 1 for that sum represented as an index in the hash table. Arrays of each pair of positions with the same value in the cumulative sum constitute a continuous range with an equal number of 1’s and 0’s.
// Now traverse the hash table and get the frequency of each element in the hash table. Let frequency be denoted as freq. For each freq > 1 we can choose any two pairs of indices of a sub-array by (freq * (freq – 1)) / 2 number of ways. Do the same for all freq and sum up the result will be the number of all possible sub-arrays containing the equal number of 1’s and 0’s.
// Also, add freq of the sum of 0 to the hash table for the final result.

// Explanation: 
// Considering all 0’s as -1, if sum[i] == sum[j], where sum[i] = sum(arr[0]+..+arr[i]) and sum[j] = sum(arr[0]+..+arr[j]) and ‘i’ is less than ‘j’, then sum(arr[i+1]+..+arr[j]) must be 0. It can only be 0 if arr(i+1, .., j) contains an equal number of 1’s and 0’s. 



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> um;
        
        int curr_sum = 0;
        for(int i=0; i<n; i++){
            curr_sum += (arr[i] == 0) ? -1 : 1;
            um[curr_sum]++;
        }
        
        int count = 0;
        for(auto it = um.begin(); it != um.end(); it++){
            if(it->second > 1){
                count += it->second * (it->second-1)/2;
            }
        }
        
        if(um.find(0) != um.end()){
            count += um[0];
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends