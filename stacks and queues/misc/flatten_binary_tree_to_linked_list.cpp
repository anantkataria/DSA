//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


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


// FIRST SELF MADE APPROACH

class Solution {
public:
    
    TreeNode* flatRecur(TreeNode* root){
        if(!root)
            return NULL;
        if(!root->left && !root->right)
            return root;
        else if(root->left == NULL){
            root->right = flatRecur(root->right);
            return root;   
        }
        else if(root->right == NULL){
            root->left = flatRecur(root->left);
            root->right = root->left;
            root->left = NULL;
            return root;
        }
        else {
            root->left = flatRecur(root->left);
            root->right = flatRecur(root->right);
            TreeNode* temp = root->left;
            while(temp->right)
                temp = temp -> right;
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return root;
        }
        
        return root;
    }
    
    void flatten(TreeNode* root) {
        if(!root)
            return;
        root = flatRecur(root);
    }
};


//MUCH SLEEK
class Solution {
public:
    
    TreeNode* flattenTree(TreeNode* node){
        if(node == NULL)
            return NULL;
        if(node->left == NULL && node->right == NULL)
            return node;
        TreeNode* leftTail = flattenTree(node->left);
        TreeNode* rightTail = flattenTree(node->right);
        
        if(leftTail != NULL){
            leftTail->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        
        return rightTail==NULL?leftTail:rightTail;
    }
    
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};