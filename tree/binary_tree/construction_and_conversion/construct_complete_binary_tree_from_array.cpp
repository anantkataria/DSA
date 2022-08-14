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

Node* getNewNode(int data){
	Node* temp = new Node(data);
	return temp;
}

Node* buildTree(vector<int>& arr, int pos){
	Node* temp = nullptr;
	if(pos < arr.size()){
		temp = getNewNode(arr[pos]);
		temp -> left = buildTree(arr, 2*pos+1);
		temp -> right = buildTree(arr, 2*pos+2);
	}
	return temp;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 6, 6};
	Node* root = buildTree(arr, 0);
	inorder(root);
	return 0;
}