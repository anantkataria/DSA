/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root){
            return vector<int>{};
        }
        
        stack<TreeNode*> s;
        TreeNode* current = root;
        vector<int> ans;
         
        while(!s.empty() || current){
            while(current){
                s.push(current);
                current = current -> left;
            }
            
            current = s.top();
            s.pop();
            ans.push_back(current->val);
            current = current -> right;
        }
        
        return ans;
    }
};