//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data = d;
		left = right = nullptr;
	}
};

void morrisTraversal(Node* root){
	Node* current = root;
	if(!current)
		return;
	while(current != NULL){
		if(current->left == NULL){
			cout << current->data << " ";
			current = current -> right;
		}
		else {
			Node* pre = current -> left;
			while(pre -> right != NULL && pre -> right != current)
				pre = pre -> right;

			if(pre -> right == NULL){
				pre -> right = current;
				current = current -> left;
			}

			else {
				pre -> right = NULL;
				cout << current -> data << " ";
				current = current -> right;
			}
		}
	}
}

Node* getNewNode(int data){
	Node* temp = new Node(data);
	return temp;
}

int main() {
	// Node* root = getNewNode(4);
	// root -> left = getNewNode(2);
	// root -> left -> left = getNewNode(1);
	// root -> left -> right = getNewNode(3);
	// root -> right = getNewNode(6);
	// root -> right -> left = getNewNode(5);
	// root -> right -> right = getNewNode(7);

	Node* root = getNewNode(4);
	root -> left = getNewNode(3);
	root -> left -> left = getNewNode(2);
	root -> left -> left -> left = getNewNode(1);
	morrisTraversal(root);
	return 0;
}