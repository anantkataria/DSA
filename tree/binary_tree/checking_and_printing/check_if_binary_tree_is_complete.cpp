#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this -> data = data;
		left = right = nullptr;
	}
};

Node* newNode(int data){
	Node* newN = new Node(data);
	return newN;
}

// https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/
// Iterative O(n)
bool isCompleteBT(Node* root){
	if(!root)
		return true;

	queue<Node*> q;
	q.push(root);

	bool flag = false;

	while(q.empty() == false){
		Node* temp = q.front();
		q.pop();

		if(temp->left){
			if(flag == true)
				return false;
			q.push(temp->left);
		}
		else 
			flag = true;

		if(temp->right){
			if(flag == true)
				return false;
			q.push(temp->right);
		}
		else 
			flag = true;
	}

	return true;
}

// https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/
// iterative simpler
// O(n)
bool isCompleteBT2(Node* root){
	if(!root)
		return true;

	queue<Node*> q;
	q.push(root);

	bool flag = false;

	while(q.empty() == false){
		Node* temp = q.front();
		q.pop();

		if(temp == NULL)
			flag = true;
		else {
			if(flag == true)
				return false;
			q.push(temp->left);
			q.push(temp->right);
		}
	}

	return true;
}

// https://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/
// recursive
// O(n)
int countTreeNodes(Node* root){
	if(!root)
		return 0;
	return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}

bool recur(Node* root, int index, int nodeCount){
	if(!root)
		return true;
	if(index >= nodeCount)
		return false;
	return recur(root->left, 2*index+1, nodeCount) && recur(root->right, 2*index+2, nodeCount);
}

bool isCompleteBT3(Node* root){
	int nodeCount = countTreeNodes(root);
	return recur(root, 0, nodeCount);
}

int main() {
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	// root->left->right = newNode(5);
	root->right->left = newNode(6);

	cout << isCompleteBT3(root);

	return 0;
}