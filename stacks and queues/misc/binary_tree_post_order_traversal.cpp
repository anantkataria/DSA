//https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return vector<int>{};
        
        stack<TreeNode*> s;
        vector<int> ans;
        
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top(); s.pop();
            ans.push_back(temp->val);
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};