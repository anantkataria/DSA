// Some Interesting Facts:  

// Inorder traversal of BST always produces sorted output.

// We can construct a BST with only Preorder or Postorder or Level Order traversal. Note that we can always get inorder traversal by sorting the only given traversal.

// Number of unique BSTs with n distinct keys is Catalan Number

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

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

Node* search(Node* root, int key){
	if(root == NULL || root->data == key)
		return root;
	else if(key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}


//iterative approach should be simple as this is kind of a tail recursion
Node* insert(Node* root, int key){
	if(!root){
		return new Node(key);
	}
	else if(key < root->data){
		root -> left = insert(root->left, key);
	}
	else {
		root -> right = insert(root->right, key);
	}
	return root;
}


//slight optimization over this is possible to avoid recursive calls after finding inorder successor
Node* deleteNode(Node* root, int key){
	if(!root)
		return NULL;
	else if(key < root->data){
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->data){
		root->right = deleteNode(root->right, key);
	}
	else {
		if(root->left == NULL && root->right == NULL){
			delete(root);
			return NULL;
		}
		else if(root->right == NULL){
			Node* temp = root;
			root = root -> left;
			delete(temp);
			return root;
		}
		else if(root->left == NULL){
			Node* temp = root;
			root = root -> right;
			delete(temp);
			return root;
		}
		//node has both left and right child

		//in order successor
		Node* temp = root -> right;
		while(temp -> left)
			temp = temp -> left;

		root -> data = temp -> data;
		root -> right = deleteNode(root->right, temp->data);
	}
	return root;
}

int main(){
	Node* root = new Node(8);
	root -> left = new Node(3);
	root -> left -> left = new Node(1);
	root -> left -> right = new Node(6);
	root -> left -> right -> left = new Node(4);
	root -> left -> right -> right = new Node(7);
	root -> right = new Node(10);
	root -> right -> right = new Node(14);
	root -> right -> right -> left = new Node(13);

	inorder(root);
	cout << endl;
	// cout << search(root, 14)->data;
	insert(root, 2);
	inorder(root);

	return 0;
}