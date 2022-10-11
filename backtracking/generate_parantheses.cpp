// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);
        return ans;
    }
    
    void backTrack(vector<string> &ans, string current, int open, int close, int max) {
        if(current.size() == max*2){
            ans.push_back(current);
            return;
        }
        
        if(open<max) backTrack(ans, current+'(', open+1, close, max);
        if(close<open) backTrack(ans, current+')', open, close+1, max);
    }
};