//https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==0)
            return {};
        if(n==1)
            return {0};
        
        vector<list<int>> adj(n);
        vector<int> degree(n, 0);
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i] == 1)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            int size = q.size();
            for(int i=0; i<size; i++){
                int temp = q.front(); q.pop();
                ans.push_back(temp);
                for(auto neighbor : adj[temp]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        
        return ans;
    }
};