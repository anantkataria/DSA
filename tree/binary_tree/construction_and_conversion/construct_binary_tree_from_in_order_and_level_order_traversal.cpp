#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this -> data = data;
		left = right = NULL;
	}
};

Node* getNewNode(int data){
	Node* newNode = new Node(data);
	return newNode;
}

int getIndexInInorder(vector<int> inOrder, int start, int end, int num){
	for(int i=start; i<=end; i++){
		if(inOrder[i] == num)
			return i;
	}
	return -1;
}

Node* buildTree(vector<int> inOrder, vector<int> levelOrder, int inStart, int inEnd, int n){
	if(inEnd < inStart)
		return NULL;

	Node* temp = getNewNode(levelOrder[0]);

	if(inStart == inEnd)
		return temp;

	int inRoot = getIndexInInorder(inOrder, inStart, inEnd, levelOrder[0]);

	unordered_set<int> leftSubTreeElements;
	for(int i=inStart; i<inRoot; i++)
		leftSubTreeElements.insert(inOrder[i]);
	cout << leftSubTreeElements.size() << "\n";

	vector<int> leftLevelOrder;
	vector<int> rightLevelOrder;
	for(int i=1; i<n; i++){
		if(leftSubTreeElements.find(levelOrder[i]) != leftSubTreeElements.end())
			leftLevelOrder.push_back(levelOrder[i]);
		else
			rightLevelOrder.push_back(levelOrder[i]);
	}

	temp -> left = buildTree(inOrder, leftLevelOrder, inStart, inRoot-1, leftLevelOrder.size());
	temp -> right = buildTree(inOrder, rightLevelOrder, inRoot+1, inEnd, rightLevelOrder.size());

	return temp;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


int main() {
	vector<int> inOrder = {4, 8, 10, 12, 14, 20, 22};
	vector<int> levelOrder = {20, 8, 22, 4, 12, 10, 14};
	Node* root = buildTree(inOrder, levelOrder, 0, inOrder.size()-1, inOrder.size());
	inorder(root);
	return 0;
}