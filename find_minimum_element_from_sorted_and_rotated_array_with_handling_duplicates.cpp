// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int low = 0;
        int high = n-1;
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(arr[mid] == arr[high]){//this means all elements from index mid to high are same
                high = mid;//in that case simply skip all those elements by putting high at mid
            }
            else if(arr[mid]<arr[high]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return arr[high];
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
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends