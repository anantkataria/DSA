// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
// soln expln : https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/discuss/68185/C%2B%2B-easy-to-understand-solution-with-thought-process-and-detailed-explanation

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int lower_bound = INT_MIN;
        for(int i=0; i<preorder.size(); i++){
            if(s.empty() || preorder[i] < s.top()){
                if(preorder[i] <= lower_bound)
                    return false;
                s.push(preorder[i]);
            }
            else {
                while(!s.empty() && s.top() < preorder[i]){
                    lower_bound = s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        
        return true;
    }
};