#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	Node* left;
	Node* right;
};

int search(char arr[], int strt, int end, char value){
	for(int i=strt; i<=end; i++){
		if(arr[i] == value)
			return i;
	}
	return -1;
}

Node* getNewNode(char data){
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node* buildTree(char in[], char pre[], int inStrt, int inEnd){
	static int preIndex = 0;
	if(inStrt > inEnd)
		return NULL;

	Node* tNode = getNewNode(pre[preIndex++]);

	if(inStrt == inEnd)
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->data);

	tNode -> left = buildTree(in, pre, inStrt, inIndex-1);
	tNode -> right = buildTree(in, pre, inIndex+1, inEnd);

	return tNode;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

int main() {

	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	int len = 6;
	Node* root = buildTree(in, pre, 0, len-1);

	inorder(root);

	return 0;
}