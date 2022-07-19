#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	int count;
	Node* left;
	Node* right;
	Node(int k){
		data = k;
		count = 1;
		left = right = NULL;
	}
};

Node* newNode(int key){
	Node* temp = new Node(key);
	return temp;
}

Node* insert(Node* root, int key){
	if(root == NULL)
		return newNode(key);
	if(root -> data == key){
		root -> count += 1;
	}
	else if(root -> data < key){
		root -> right = insert(root->right, key);
	}
	else {
		root -> left = insert(root->left, key);
	}
	return root;
}

Node* getMin(Node* root){
	while(root -> left){
		root = root -> left;
	}
	return root;
}

Node* deleteNode(Node* root, int key){
	if(!root){
		return NULL;
	}
	if(root -> data == key){
		if(root -> count > 1){
			root -> count -= 1;
			return root;
		}
		else {
			if(!root->left && !root->right){
				delete(root);
				return NULL;
			}
			if(!root->right){
				Node* temp = root->left;
				delete(root);
				return temp;
			}
			if(!root->left){
				Node* temp = root->right;
				delete(root);
				return temp;
			}
			Node* temp = getMin(root->right);
			root -> data = temp -> data;
			root -> count = temp -> count;
			root -> right = deleteNode(root->right, temp->data);
		}
	}
	else if(root -> data < key){
		root -> right = deleteNode(root->right, key);
	}
	else {
		root -> left = deleteNode(root->left, key);
	}
	return root;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << "(" << root -> data << ", " << root -> count << ")" << endl;
	inorder(root->right); 
}

int main() {
	Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);	

    inorder(root);
    root = deleteNode(root, 12);
    cout << endl << endl;
    inorder(root);

	return 0;
}