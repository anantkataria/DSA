#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		left = right = nullptr;
	}
};

Node* constructTreeUtil(vector<int>& pre, vector<int>& post, int* preIndex, int l, int h){
	//base case
	if(*preIndex  >= pre.size() || l > h)
		return nullptr;

	Node* root = new Node(pre[*preIndex]);
	*preIndex = *preIndex + 1;

	if(l == h)
		return root;

	int i;
	for(i=l; i<=h; i++){
		if(post[i] == pre[*preIndex])
			break;
	}

	if(i <= h) {
		root -> left = constructTreeUtil(pre, post, preIndex, l, i);
		root -> right = constructTreeUtil(pre, post, preIndex, i+1, h-1);
	}

	return root;
}

Node* constructTree(vector<int>& pre, vector<int>& post){
	int preIndex = 0;
	return constructTreeUtil(pre, post, &preIndex, 0, pre.size()-1);
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {

	vector<int> preorder = {1, 2, 4, 5, 3, 6};
	vector<int> postorder = {4, 5, 2, 6, 3, 1};

	Node* root = constructTree(preorder, postorder);
	inorder(root);

	return 0;
}