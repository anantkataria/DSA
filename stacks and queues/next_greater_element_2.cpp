// soln 1
// After one pass of mono-stack, just do another one. The maximum number should output -1
// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> s;
        for(int i=0; i<nums.size(); i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0; i<nums.size(); i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                ans[s.top()] = nums[i];
                s.pop();
            }
        }
        
        while(!s.empty()){
            ans[s.top()] = -1;
            s.pop();
        }
        
        return ans;
    }
};