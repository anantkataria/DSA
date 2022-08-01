//https://www.geeksforgeeks.org/reverse-tree-path/

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

Node* getNewNode(int d){
	Node* newNode = new Node(d);
	return newNode;
}

Node* reverseTreePathUtil(Node* root, int data, map<int, int>& temp, int level, int& nextPos){
	if(!root)
		return NULL;
	if(root->data == data){
		temp[level] = root->data;
		root->data = temp[nextPos];
		nextPos++;
		return root;
	}
	temp[level] = root->data;
	Node* left;
	Node* right;
	left = reverseTreePathUtil(root->left, data, temp, level+1, nextPos);
	if(left == NULL) right = reverseTreePathUtil(root->right, data, temp, level+1, nextPos);

	if(left || right){
		root->data = temp[nextPos];
		nextPos++;
		return (left ? left : right);
	}

	return NULL;
}

void reverseTreePath(Node* root, int data){
	map<int, int> temp;
	int nextPos = 0;
	reverseTreePathUtil(root, data, temp, 0, nextPos);
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

//other method based on : print all tree paths from root
void reverseTreePath2Util(Node* root, vector<Node*> path, int data){
	if(!root)
		return;

	path.push_back(root);

	if(root->data == data){
		int i = 0;
		int j = path.size()-1;
		while(i<j){
			int temp = path[i]->data;
			path[i]->data = path[j]->data;
			path[j]->data = temp;
			i++;
			j--;
		}
		return;
	}

	reverseTreePath2Util(root->left, path, data);
	reverseTreePath2Util(root->right, path, data);
}

void reverseTreePath2(Node* root, int data){
	vector<Node*> path;
	reverseTreePath2Util(root, path, data);
}

int main() {
	Node* root = getNewNode(7);
	root -> left = getNewNode(6);
	root -> right = getNewNode(5);
	root -> left -> left = getNewNode(4);
	root -> left -> right = getNewNode(3);
	root -> right -> left = getNewNode(2);
	root -> right -> right = getNewNode(1);

	int data = 4;

	inorder(root);
	cout << endl;

	reverseTreePath2(root, data);

	inorder(root);

	return 0;
}