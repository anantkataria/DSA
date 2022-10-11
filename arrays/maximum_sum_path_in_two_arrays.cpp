// https://leetcode.com/problems/get-the-maximum-score/

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0;
        long sum1 = 0, sum2 = 0;
        while(i1 < nums1.size() || i2 < nums2.size()){
            if(i1 < nums1.size() && (i2 == nums2.size() || nums1[i1] < nums2[i2])){
                sum1 += nums1[i1];
                i1++;
            }
            else if(i2 < nums2.size() && (i1 == nums1.size() || nums2[i2] < nums1[i1])){
                sum2 += nums2[i2];
                i2++;
            }
            else {
                sum1 = sum2 = max(sum1, sum2)+nums1[i1];
                i1++;
                i2++;
            }
        }
        
        return max(sum1, sum2)%1000000007;
    }
};




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int i=0;
        int j=0;
        int sum1 = 0;
        int sum2 = 0;
        int ans = 0;
        while(i<l1 && j<l2){
            if(A[i] < B[j]){
                sum1+=A[i];
                i++;
            }
            else if(B[j] < A[i]){
                sum2+=B[j];
                j++;
            }
            else{
                ans = ans + max(sum1, sum2) + A[i];
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        while(i < l1){
            sum1 += A[i++];
        }
        while(j < l2){
            sum2 += B[j++];
        }
        
        ans += max(sum1, sum2);
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends