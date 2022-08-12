class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses, 0);
        
        list<int>* adj = new list<int>[numCourses];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
            
            cnt++;
        }
        
        if(cnt != numCourses)
            return false;
        return true;
        
        
    }
};