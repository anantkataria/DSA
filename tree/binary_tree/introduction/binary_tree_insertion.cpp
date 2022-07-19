#include<bits/stdc++.h>
using namespace std;

class Btree {
public:
	int data;
	Btree* left;
	Btree* right;

	Btree(int x){
		data = x;
		left = right = NULL;
	}
	Btree* getLeft() {
		return left;
	}
	Btree* getRight() {
		return right;
	}
};

Btree* getNewNode(int x){
	Btree *newNode = new Btree(x);
	return newNode;
}

Btree* insert(Btree* root, int v){
	if(!root){
		return getNewNode(v);
	}

	queue<Btree*> q;
	q.push(root);

	while(!q.empty()){
		Btree* temp = q.front();
		q.pop();

		if(temp -> left){
			q.push(temp->left);
		}
		else {
			temp -> left = getNewNode(v);
			break;
		}
		if(temp -> right){
			q.push(temp -> right);
		}
		else{
			temp -> right = getNewNode(v);
			break;
		}
	}

	return root;
}

Btree* insertRecur(Btree* root, int v){
	if(!root){
		return getNewNode(v);
	}
	
	if(!root -> left){
		root -> left = getNewNode(v);
		return root;
	}
	else {
		root -> left = insertRecur(root->left, v);
	}

	if(!root -> right){
		root -> right = getNewNode(v);
		return root;
	}
	else {
		root -> right = insertRecur(root->right, v);
	}

	return root;
}

void inorder(Btree* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	Btree* root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	inorder(root);
	cout << endl;
	// insert(root, 5);
	root = insertRecur(root, 5);
	cout << endl;
	inorder(root);
	return 0;
}