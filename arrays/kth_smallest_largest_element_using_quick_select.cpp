// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    
    int partition(int arr[], int l, int r){
        int i = l;
        int x = arr[r];
        
        for(int j=l; j<=r-1; j++){
            if(arr[j] < x){
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
    
    int randomPartition(int arr[], int l, int r){
        int n = r-l+1;
        int pivot = rand()%n;
        swap(arr[l+pivot], arr[r]);
        return partition(arr, l, r);
    }
    
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        // if(k>0 && k<=(r-l+1)){
            int pos = randomPartition(arr, l, r);
            
            if(pos == k-1){
                return arr[pos];
            }
            else if(pos > k-1){
                return kthSmallest(arr, l, pos-1, k);
            }
            return kthSmallest(arr, pos+1, r, k);
        // }
        // return INT_MAX;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends