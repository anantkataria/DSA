// Input:
// n = 7
// arr[] = {1, 5, 3, 4, 3, 5, 6}
// Output: 2
// Explanation: 
// 5 is appearing twice and 
// its first appearence is at index 2 
// which is less than 3 whose first 
// occuring index is 3.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        //map<element, pair(first_element_index, frequency)>
        unordered_map<int, int> map_freq;
        unordered_map<int, int> map_first_index;
        
        for(int i=0; i<n; i++){
            map_freq[arr[i]]++;
            if(map_first_index.find(arr[i]) == map_first_index.end())
                map_first_index[arr[i]] = i+1;
        }
        
        vector<int> repeating_ele;
        for(auto i = map_freq.begin(); i != map_freq.end(); i++){
            if(i->second > 1)
                repeating_ele.push_back(i->first);
        }
        
        int min_i = INT_MAX;
        for(int i=0; i<repeating_ele.size(); i++){
            auto itr = map_first_index.find(repeating_ele[i]);
            if(itr->second < min_i)
                min_i = itr->second;
        }
        
        if(min_i == INT_MAX)
            return -1;
        return min_i;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends