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

void customLevelOrderTraversal(Node* root){
	if(!root)
		return;
	cout << root->data << " ";
	if(!root->left && !root->right){
		return;
	}
	cout << root->left->data << " " << root->right->data << " ";
	queue<Node*> q;
	q.push(root->left);
	q.push(root->right);

	if(!root->left->left)
		return;

	while(!q.empty()){
		Node* first = q.front(); q.pop();
		Node* second = q.front(); q.pop();

		cout << first -> left -> data << " " << second -> right -> data << " " << first -> right -> data << " " << second -> left -> data << " ";

		if(first->left->left){
			q.push(first->left);
			q.push(second->right);
			q.push(first->right);
			q.push(second->left);
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
	root -> left -> left -> left = getNewNode(8);
	root -> left -> left -> right = getNewNode(9);
	root -> left -> right -> left = getNewNode(10);
	root -> left -> right -> right = getNewNode(11);
	root -> right -> left -> left = getNewNode(12);
	root -> right -> left -> right = getNewNode(13);
	root -> right -> right -> left = getNewNode(14);
	root -> right -> right -> right = getNewNode(15);

	customLevelOrderTraversal(root);

	return 0;
}