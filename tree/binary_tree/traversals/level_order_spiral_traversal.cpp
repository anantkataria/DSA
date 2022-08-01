//https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node* getNewNode(int d){
    Node* newNode = new Node(d);
    return newNode;
}

int getHeight(Node* root){
    if(!root)
        return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    if(lHeight > rHeight){
        return lHeight + 1;
    }
    return rHeight + 1;
}

void goFromRightToLeft(Node* root, int level){
    if(!root)
        return;
    if(level == 1){
        cout << root -> data << " ";
        return;
    }
    level = level - 1;
    goFromRightToLeft(root->right, level);
    goFromRightToLeft(root->left, level);
}

void goFromLeftToRight(Node* root, int level){
    if(!root)
        return;
    if(level == 1){
        // v.push_back(root->data);
        cout << root -> data << " ";
        return;
    }
    goFromLeftToRight(root->left, level-1);
    goFromLeftToRight(root->right, level-1);
}

vector<int> findSpiral(Node *root)
{
    vector<int> v;
    if(!root)
        return v;
    cout << "x" << endl;
    int height = getHeight(root);
    
    for(int i=1; i<=height; i++){
        if(i%2!=0){
            goFromRightToLeft(root, i);
        }
        else {
            goFromLeftToRight(root, i);
        }
    }
    
    return v;
}

//better solution
void spiralIterative(Node* root){
    if(!root)
        return;
    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* temp = s1.top(); s1.pop();
            cout << temp -> data << " ";
            if(temp->right){
                s2.push(temp->right);
            }
            if(temp->left){
                s2.push(temp->left);
            }
        }
        while(!s2.empty()){
            Node* temp = s2.top(); s2.pop();
            cout << temp -> data << " ";
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
        }
    }
}

int main() {

    Node* root = getNewNode(1);
    root -> left = getNewNode(2);
    root -> right = getNewNode(3);
    root -> left -> left = getNewNode(4);
    root -> left -> right = getNewNode(5);
    root -> right -> left = getNewNode(6);
    root -> right -> right = getNewNode(7);
    root -> right -> left -> left = getNewNode(8);
    root -> right -> left -> right = getNewNode(9);

    // findSpiral(root);
    spiralIterative(root);

    return 0;
}