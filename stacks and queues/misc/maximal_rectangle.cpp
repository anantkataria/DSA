// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    
    int largestRectangleInHistogram(vector<int> heights){
        if(heights.size() == 1)
            return heights[0];
        
        int maxArea = 0;
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<heights.size(); i++){
            while(s.top() != -1 && heights[i] < heights[s.top()]){
                int current = heights[s.top()];
                s.pop();
                int dist = i-s.top()-1;
                int area = dist*current;
                maxArea = max(maxArea, area);
            }
            s.push(i);
        }
        
        while(s.top() != -1){
            int current = heights[s.top()];
            s.pop();
            maxArea = max(maxArea, current*(heights.size()-s.top()-1));
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size(), 0);
        int maxArea = 0;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1')
                    dp[j] += 1;
                else
                    dp[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleInHistogram(dp));
        }
        
        return maxArea;
    }
};