// https://leetcode.com/problems/binary-search-tree-iterator/


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
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while(!s.empty())
            s.pop();
        while(root){
            s.push(root);
            root = root -> left;
        }
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        int ans = temp -> val;
        temp = temp -> right;
        while(temp){
            s.push(temp);
            temp = temp -> left;
        }
        return ans;
    }
    
    bool hasNext() {
        if(!s.empty())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */