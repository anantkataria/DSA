// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int curri;
       int previ;
       int nexti;
       
       //I forgot the edge case when there is only one element
       if(n == 1){
           return 0;
       }
       
       for( curri=0; curri<n; curri++){
           previ = curri-1;
           nexti = curri+1;
           if(previ >= 0 && nexti < n){
               if(arr[curri]>=arr[previ] && arr[curri]>=arr[nexti]){
                   return curri;
               }
           }
           else if (previ >= 0){
               if(arr[curri]>=arr[previ]){
                   return curri;
               }
           }
           else {
               if(arr[curri]>=arr[nexti]){
                   return curri;
               }
           }
       }
       
       return curri;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}  // } Driver Code Ends