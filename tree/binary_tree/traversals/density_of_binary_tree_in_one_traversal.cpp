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

int getHeightSize(Node* root, int& size){
	if(!root)
		return 0;
	size++;
	int lheight = getHeightSize(root->left, size);
	int rheight = getHeightSize(root->right, size);
	if(lheight > rheight)
		return lheight + 1;
	return rheight + 1;
}

int main() {
	Node* root = getNewNode(1);
	root -> left = getNewNode(2);
	root -> right = getNewNode(3);
	root -> left -> left = getNewNode(4);
	root -> left -> right = getNewNode(5);
	root -> left -> right -> right = getNewNode(6);
	root -> right -> left = getNewNode(7);
	root -> right -> right = getNewNode(8);

	int height = 0;
	int size = 0;
	height = getHeightSize(root, size);

	cout << "height = " << height << endl;
	cout << "size = " << size << endl;
	cout << "density = " << size/height;

	return 0;
}