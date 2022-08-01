//https://www.geeksforgeeks.org/inorder-succesor-node-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d){
		data = d;
		left = right = NULL;
	} 
};

Node* getNewNode(int d){
	Node* newNode = new Node(d);
	return newNode;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

Node* temp = getNewNode(0);

Node* getSuccessorRecursive(Node* root, Node* x){
	if(!root)
		return NULL;
	if(root == x || (temp = getSuccessorRecursive(root->left, x)) || (temp = getSuccessorRecursive(root->right, x))){
		if(temp){
			if(root->left == temp){
				cout << "Inorder successor : " << root->data;
				return NULL;
			}
		}
		return root;
	}
	return NULL;
}

int getLeftMost(Node* temp){
	while(temp -> left){
		temp = temp -> left;
	}
	return temp -> data;
}

Node* getRightMost(Node* temp){
	while(temp -> right){
		temp = temp -> right;
	}
	return temp;
}

void inorderSuccessor(Node* root, Node* x){
	if(x->right){
		cout << "Inorder successor : " << getLeftMost(x->right);
	}
	else {
		if(x == getRightMost(root)){
			cout << "Inorder successor does not exist for the given node.";
		}
		else {
			//this case happens when the x node does not have right child
			//so its successor is going to be one of its parent node.
			getSuccessorRecursive(root, x);
		}
	}
}

int main(){
	Node* root = getNewNode(1);
	root -> left = getNewNode(2);
	root -> right = getNewNode(3);
	root -> left -> left = getNewNode(4);
	root -> left -> right = getNewNode(5);
	root -> right -> left = getNewNode(6);
	root -> right -> right = getNewNode(7);

	// inorder(root);

	inorderSuccessor(root, root->left->right);

	return 0;
}