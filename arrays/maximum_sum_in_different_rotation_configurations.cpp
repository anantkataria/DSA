//https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1#
// array might not be sorted

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{
    int arr_sum = 0;
    for(int i=0; i<n; i++){
        arr_sum += arr[i];
    }
    
    int curr_sum = 0;
    for(int i=0; i<n; i++){
        curr_sum += arr[i]*i;
    }
    
    int new_sum;
    int max_sum = curr_sum;
    for(int i=1; i<n; i++){
        new_sum = curr_sum - (arr_sum - arr[i-1]) + (n-1)*arr[i-1];
        max_sum = max(max_sum, new_sum);
        curr_sum = new_sum;
    }
    
    return max_sum;
}