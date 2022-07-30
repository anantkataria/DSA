//https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
// Complexity Improvements are possible in the code below

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}

// } Driver Code Ends


/*prints the post order traversal of the 
tree */

int search(int in[], int val, int n){
    for(int i=0; i<n; i++){
        if(in[i] == val)
            return i;
    }
    return -1;
}

void printPostOrder(int in[], int pre[], int n)
{
    if(n <= 0)
        return;
    int index = search(in, pre[0], n);
    
    if(index > 0){
        printPostOrder(in, pre+1, index);
    }
    
    if(index < n-1){
        printPostOrder(in+index+1, pre+index+1, n-index-1);
    }
    
    cout << pre[0] << " ";
}