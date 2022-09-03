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

Node* bstFromPreorder(int pre[], int start, int end){
	if(start > end)
		return nullptr;

	int rootData = pre[start];
	Node* newNode = new Node(rootData);

	if(start == end)
		return newNode;

	start++;
	int newEnd;
	for(newEnd=start; newEnd<=end; newEnd++){
		if(pre[newEnd] < rootData)
			continue;
		else
			break;
	}

	newNode -> left = bstFromPreorder(pre, start, newEnd-1);
	newNode -> right = bstFromPreorder(pre, newEnd, end);

	return newNode;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

int main() {
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(pre)/sizeof(pre[0]);
	
	Node* root = bstFromPreorder(pre, 0, size-1);
	inorder(root);

	return 0;
}