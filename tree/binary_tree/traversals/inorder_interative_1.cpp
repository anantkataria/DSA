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

Node* getNewNode(int data){
	Node* newNode = new Node(data);
	return newNode;
}

void inorder(Node* root){
	Node* curr = root;
	stack<Node*> s;
	while(curr != NULL || s.empty() == false){
		while(curr != NULL){
			s.push(curr);
			curr = curr -> left;
		}

		curr = s.top(); s.pop();
		cout << curr -> data << " ";

		curr = curr -> right;
	}
}

int main() {
	Node* root = getNewNode(1);
	root -> left = getNewNode(2);
	root -> right = getNewNode(3);
	root -> left -> left = getNewNode(4);
	root -> left -> right = getNewNode(5);
	inorder(root);
	return 0;
}