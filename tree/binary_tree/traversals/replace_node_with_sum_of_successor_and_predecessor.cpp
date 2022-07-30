//https://www.geeksforgeeks.org/replace-node-binary-tree-sum-inorder-predecessor-successor/

// second method seems wrong in the code (check in the website) 

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node(int d) {
		data = d;
		left = right = NULL;		
	}
};

Node* getNewNode(int data){
	Node* newNode = new Node(data);
	return newNode;
}

void inorder(Node* root, vector<int>& arr){
	if(!root)
		return;
	inorder(root->left, arr);
	arr.push_back(root->data);
	inorder(root->right, arr);
}

void replaceWithSum(Node* root, int* i, vector<int>& arr){
	if(!root)
		return;
	replaceWithSum(root->left, i, arr);
	root -> data = arr[*i-1] + arr[*i+1];
	*i = *i + 1;
	replaceWithSum(root->right, i, arr);
}

void inorderNormal(Node* root){
	if(!root)
		return;
	inorderNormal(root->left);
	cout << root -> data << " ";
	inorderNormal(root->right);
}

// void optimizedReplacement(Node* root, Node* prev, int& prevPrevVal){
// 	if(!root)
// 		return;
// 	if(prev == NULL){

// 	}
// }

void inOrderTraverse(Node* root, Node* &prev, int &prevVal)
 {
     if(root == NULL) return;
     inOrderTraverse(root->left, prev, prevVal);
     if(prev == NULL)
     {
         prev = root;
         prevVal = 0;
     }
     else
     {
         int temp = prev->data;
         prev->data = prevVal + root->data;
         prev = root;
         prevVal = temp;
     }
     inOrderTraverse(root->right, prev, prevVal);
 }

int main() {
	Node* root = getNewNode(1);
	root -> left = getNewNode(2);
	root -> right = getNewNode(3);
	root -> left -> left = getNewNode(4);
	root -> left -> right = getNewNode(5);
	root -> right -> left = getNewNode(6);
	root -> right -> right = getNewNode(7);

	inorderNormal(root);
	cout << endl;

	vector<int> arr = {0};
	inorder(root, arr);
	arr.push_back(0);

	// for(int i=0; i<arr.size(); i++)
	// 	cout << arr[i] << " ";

	int i = 1;
	replaceWithSum(root, &i, arr);

	// int prevVal = -1;
	// Node* prev = NULL;
	// inOrderTraverse(root, prev, prevVal);

	inorderNormal(root);

	return 0;
}