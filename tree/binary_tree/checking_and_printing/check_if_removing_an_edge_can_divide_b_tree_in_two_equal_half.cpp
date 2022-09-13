// https://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int val){
		this -> data = val;
		left = right = NULL;
	}
};


int count(Node* root){
	if(!root)
		return 0;
	return count(root->left) + count(root->right) + 1;
}

// O(n^2) time <- Optimization over this is O(n) and it is must to look soln
bool checkRec(Node* root, int n){
	if(!root)
		return true;
	if(count(root) == n-count(root))
		return true;
	return checkRec(root->left, n) || checkRec(root->right, n);
}

bool check(Node* root){
	int n = count(root);
	return checkRec(root, n);
}

int main() {

	struct Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(4);

    cout << check(root);

	return 0;
}