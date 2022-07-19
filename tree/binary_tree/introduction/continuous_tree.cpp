#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int k){
		data = k;
		left = right = NULL;
	}
};

Node* addNewNode(int k){
	Node* temp = new Node(k);
	return temp;
}

bool helper(Node* node, int parentVal){
	if(!node)
		return true;
	int diff = abs(node->data - parentVal);
	if(diff != 1)
		return false;
	return helper(node->left, node->data) && helper(node->right, node->data);
}

bool checkContinuous(Node* root){
	if(!root)
		return false;
	return helper(root->left, root->data) && helper(root->right, root->data);
}

bool continuousRecur(Node* root){
	if(!root)
		return true;
	if(!root->left && !root->right)
		return true;
	if(!root->left)
		return abs(root->data-root->right->data)==1 && continuousRecur(root->right);
	if(!root->right)
		return abs(root->data-root->left->data)==1 && continuousRecur(root->left);
	return abs(root->data-root->left->data)==1
		&& abs(root->data-root->right->data)==1
		&& continuousRecur(root->left)
		&& continuousRecur(root->right);
}

//BFS queue approach (iterative)
bool continuousIterative(Node* root){
	if(!root)
		return false;
	int flag = 1;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->left){
			if(abs(temp->data-temp->left->data)==1){
				q.push(temp->left);
			}else{
				flag = 0;
				break;
			}
		}
		if(temp->right){
			if(abs(temp->data-temp->right->data)==1){
				q.push(temp->right);
			}
			else {
				flag = 0;
				break;
			}
		}
	}

	return flag;
}

int main() {
	Node* root = addNewNode(3);
	root -> left = addNewNode(2);
	root -> right = addNewNode(4);
	root -> left -> left = addNewNode(5);
	root -> left -> right = addNewNode(3);
	root -> right -> right = addNewNode(5);
	cout << continuousIterative(root);
	return 0;
}