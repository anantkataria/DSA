// https://www.geeksforgeeks.org/deletion-binary-tree/

#include<bits/stdc++.h>
using namespace std;

class Btree {
public:
	int data;
	Btree* left;
	Btree* right;
	Btree(int k){
		data = k;
		left = right = NULL;
	}
};

Btree* getNewNode(int k){
	Btree* newNode = new Btree(k);
	return newNode;
}

void deleteDeepest(Btree* root, Btree* node){
	queue<Btree*> q;
	q.push(root);

	Btree* temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == node){
			temp = NULL;
			delete(node);
			return;
		}
		if (temp->right) {
            if (temp->right == node) {
                temp->right = NULL;
                delete (node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == node) {
                temp->left = NULL;
                delete (node);
                return;
            }
            else
                q.push(temp->left);
        }
	}
}


Btree* deleteNode(Btree* root, int k){
	if(!root)
		return root;
	if(!root->left && !root->right){
		if(root->data == k)
			return NULL;
		else 
			return root;
	}
	// cout << "a";
	queue<Btree*> q;
	q.push(root);

	Btree* temp;
	Btree* keyNode;

	while(!q.empty()){
		// cout << "b";
		temp = q.front();
		q.pop();
		if(temp -> data == k)
			keyNode = temp;
		if(temp -> left)
			q.push(temp->left);
		if(temp -> right)
			q.push(temp->right);
	}

	if(keyNode){
		int x = temp->data;
        deleteDeepest(root, temp);
        keyNode->data = x;
	}
	// cout << "g";
	return root;
}

void inorder(Btree* root){
	// cout << endl << "xx" << endl;
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

int main() {
	Btree* root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	inorder(root);
	cout << endl;
	root = deleteNode(root, 5);
	cout << endl;
	inorder(root);
	return 0;
}