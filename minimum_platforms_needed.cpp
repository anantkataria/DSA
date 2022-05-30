// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int plat_needed = 1;
    	int final = 1;
    	
    	int i = 1; //LOOK CLOSELY HERE
    	int j = 0;
    	
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        plat_needed++;
    	        i++;
    	    }
    	    else{
    	        plat_needed--;
    	        j++;
    	    }
    	    
    	    if(plat_needed > final)
    	        final = plat_needed;
    	}
    	
    	return final;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends

/*
// LINEAR TIME IMPLEMENTATION
// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        multiset<pair<int, char>> order;
        for(int i=0; i<n; i++){
            order.insert({arr[i], 'a'});
            order.insert({dep[i], 'd'});
        }
        
        int result=0;
        int plat_needed = 0;
        for(auto item:order){
            if(item.second == 'a'){
                plat_needed++;
            }
            else{
                plat_needed--;
            }
            
            if(plat_needed > result)
                result = plat_needed;
        }
        
        return result;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
*/