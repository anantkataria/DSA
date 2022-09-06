// https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/

//Method 1 : Simple

//Method 2 : O(n)
class Solution
{
    public:
    
    bool isLeaf(Node* root){
        if(!root)
            return false;
        if(!root->left && !root->right)
            return true;
        return false;
    }
    
    bool isSumTree(Node* root)
    {
        if(root == NULL || isLeaf(root))
            return true;
        
        if(isSumTree(root->left) && isSumTree(root->right)){
            int ls;
            if(root->left == NULL)
                ls = 0;
            else if(isLeaf(root->left))
                ls = root->left->data;
            else
                ls = 2 * root->left->data;
                
            int rs;
            if(root->right == NULL)
                rs = 0;
            else if(isLeaf(root->right))
                rs = root->right->data;
            else
                rs = 2 * root->right->data;
                
            return root->data == (ls + rs);
        }
        return false;
    }
};