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

void getoutOfStack(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}

void customLevelOrderTraversal(Node* root){
	if(!root)
		return;
	if(!root->left && !root->right){
		cout << root->data;
		return;
	}
	stack<int> s;
	queue<Node*> q;
	s.push(root->data);
	s.push(root->right->data);
	s.push(root->left->data);
	if(!root->left->left){
		getoutOfStack(s);
		return;
	}
	q.push(root->left);
	q.push(root->right);

	while(!q.empty()){
		Node* first = q.front(); q.pop();
		Node* second = q.front(); q.pop();

		s.push(second->left->data);
		s.push(first->right->data);
		s.push(second->right->data);
		s.push(first->left->data);

		if(first->left->left){
			q.push(first->right);
			q.push(second->left);
			q.push(first->left);
			q.push(second->right);
		}
	}

	getoutOfStack(s);
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