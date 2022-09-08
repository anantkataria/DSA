// https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// https://www.youtube.com/watch?v=tJK7vjNKdLY

// time complexity here will be less than O(nlogn) 
// time complexity will be O(k) + O(n-(k+1)*logk) + O(klogk)

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        int size = n==k?k:k+1;

        // O(k)
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr+size);
        
        vector<int> ans;

        // O(n-(k+1)logk)
        for(int i=k+1; i<n; i++){
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        
        // O(klogk)
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};