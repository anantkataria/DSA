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

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

void inorderIterative(Node* root) {
	stack<Node*> s;
	Node* current = root;

	while(current || !s.empty()){
		while(current){
			s.push(current);
			current = current -> left;
		}
		current = s.top();
		cout << current->data << " ";
		s.pop();
		current = current -> right;
	}
}

void inorderMorris(Node* root){
	if(!root){
		return;
	}
	Node* current = root;
	while(current){
		if(!current->left){
			cout << current -> data << " ";
			current = current -> right;
		}
		else {
			Node* predecessor = current->left;
			while(predecessor->right != NULL && predecessor->right != current){
				predecessor = predecessor -> right;
			}

			if(predecessor->right == NULL){
				predecessor -> right = current;
				current = current -> left;
			}
			else {
				predecessor -> right = NULL;
				cout << current -> data << " ";
				current = current -> right;			
			}
		}
	}
}

void preorder(Node* root){
	if(!root)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

//https://www.geeksforgeeks.org/iterative-preorder-traversal/
void preorderIterative(Node* root){
	if(!root)
		return;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()){
		Node* temp = s.top();
		s.pop();
		cout << temp -> data << " ";
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}

//based on inorder iterative above
void preorderIterative2(Node* root){
	stack<Node*> s;
	Node* current = root;

	while(current || !s.empty()){
		while(current){
			cout << current->data << " ";
			s.push(current);
			current = current -> left;
		}
		current = s.top();
		// cout << current->data << " ";
		s.pop();
		current = current -> right;
	}
}

// https://www.geeksforgeeks.org/iterative-preorder-traversal/
void preorderIterative_improvement_over_preorderIterative2(Node* root){
	if(!root)
		return;
	stack<Node*> s;
	Node* current = root;
	while(current != NULL || !s.empty()){
		while(current != NULL){
			cout << current -> data << " ";
			if(current -> right)
				s.push(current->right);
			current = current -> left;
		}
		if(!s.empty()){
			current = s.top();
			s.pop();	
		}
	}
}

// https://www.geeksforgeeks.org/morris-traversal-for-preorder/
void preorderMorris(Node* root){
	Node* current = root;
	while(current != NULL){
		if(current->left == NULL){
			cout << current -> data << " ";
			current = current -> right;
		}
		else {
			Node* pred = current -> left;
			while(pred -> right != NULL && pred -> right != current){
				pred = pred -> right;
			}

			if(pred -> right == NULL){
				cout << current -> data << " ";
				pred -> right = current;
				current = current -> left;
			}
			else {
				pred -> right = NULL;
				current = current -> right;
			}
		}
	}
}

void postorder(Node* root){
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root -> data << " ";
}

// https://www.geeksforgeeks.org/iterative-postorder-traversal/
//two stack soln
void postorderIterative(Node* root){
	if(!root)
		return;
	stack<Node*> s;
	stack<Node*> reversePostorder;
	s.push(root);
	while(!s.empty()){
		Node* temp = s.top();
		s.pop();
		reversePostorder.push(temp);
		if(temp->left)
			s.push(temp->left);
		if(temp->right)
			s.push(temp->right);
	}

	while(!reversePostorder.empty()){
		cout << reversePostorder.top() -> data << " ";
		reversePostorder.pop();
	}
}

//https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
//one stack soln


//https://www.geeksforgeeks.org/postorder-traversal-binary-tree-without-recursion-without-stack/
void postOrderIterativeDFS(Node* root){
	unordered_map<Node*, Node*> parent;
	parent[root] = NULL;
	Node* traveller = root;

	while(traveller != NULL){
		if(traveller->left && parent.find(traveller->left) == parent.end()){
			parent[traveller->left] = traveller;
			traveller = traveller -> left;
		}
		else if(traveller->right && parent.find(traveller->right) == parent.end()){
			parent[traveller->right] = traveller;
			traveller = traveller -> right;
		}
		else {
			cout << traveller -> data << " ";
			traveller = parent[traveller];
		}
	}
}

int main() {

	Node* root = new Node(1);
	root -> left = new Node(2);
	root -> left -> left = new Node(4);
	root -> left -> left -> left = new Node(7);
	root -> left -> right = new Node(5);
	root -> left -> right -> right = new Node(8);
	root -> left -> right -> right -> left = new Node(9);
	root -> right = new Node(3);
	root -> right -> right = new Node(6);

	postorder2(root);

	return 0;
}