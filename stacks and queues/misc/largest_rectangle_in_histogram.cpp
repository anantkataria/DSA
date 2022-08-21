// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    
    int max(int a, int b){
        return a>b?a:b;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        s.push(-1);
        for(int i=0; i<heights.size(); i++){
            while(s.top() != -1 && heights[s.top()] > heights[i]){
                int curr = heights[s.top()];
                s.pop();
                maxArea = max(maxArea, curr*(i-s.top()-1));
            }
            s.push(i);
        }
        
        while(s.top() != -1) {
            int curr = heights[s.top()];
            s.pop();
            maxArea = max(maxArea, curr*(heights.size()-s.top()-1));
        }
        
        return maxArea;
    }
};