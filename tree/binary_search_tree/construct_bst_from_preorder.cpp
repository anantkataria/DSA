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

// O(n^2)
Node* bstFromPreorder(int pre[], int start, int end){
	if(start > end)
		return nullptr;

	int rootData = pre[start];
	Node* newNode = new Node(rootData);

	if(start == end)
		return newNode;

	start++;
	int newEnd;
	for(newEnd=start; newEnd<=end; newEnd++){
		if(pre[newEnd] < rootData)
			continue;
		else
			break;
	}

	newNode -> left = bstFromPreorder(pre, start, newEnd-1);
	newNode -> right = bstFromPreorder(pre, newEnd, end);

	return newNode;
}

Node* util2(Node* root, int newData){
	if(!root)
		return new Node(newData);
	if(newData < root->data)
		root -> left = util2(root->left, newData);
	else 
		root -> right = util2(root->right, newData);
	return root;
}

//O(n^2)
Node* bstFromPreorder2(int pre[], int size){
	Node* root = nullptr;

	for(int i=0; i<size; i++)
		root = util2(root, pre[i]);

	return root;
}

//O(n)
Node* bstFromPreorder3(int pre[], int* preIndex, int min, int max, int size){
	if(*preIndex >= size)
		return nullptr;

	Node* newNode = nullptr;
	if(pre[*preIndex] > min && pre[*preIndex] < max){
		newNode = new Node(pre[*preIndex]);
		*preIndex = *preIndex + 1;
		if(*preIndex < size){
			newNode -> left = bstFromPreorder3(pre, preIndex, min, newNode->data, size);
		}
		if(*preIndex < size){
			newNode -> right = bstFromPreorder3(pre, preIndex, newNode->data, max, size);
		}
	}
	return newNode;
}

//O(n) Iterative
Node* bstFromPreorder4(int pre[], int size){
	if(size < 1)
		return nullptr;

	stack<Node*> s;
	
	Node* root = new Node(pre[0]);
	s.push(root);
	
	for(int i=1; i<size; i++){
		Node* temp = nullptr;
		while(!s.empty() && pre[i] > s.top()->data){
			temp = s.top();
			s.pop();
		}

		Node* newNode = new Node(pre[i]);
		if(temp != nullptr)
			temp -> right = newNode;
		else
			s.top()->left = newNode;

		s.push(newNode);
	}
	return root;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root -> data << " ";
	inorder(root->right);
}

int main() {
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof(pre)/sizeof(pre[0]);
	
	// Node* root = bstFromPreorder(pre, 0, size-1);
	// Node* root = bstFromPreorder2(pre, size);
	// int preIndex = 0;
	// Node* root = bstFromPreorder3(pre, &preIndex, INT_MIN, INT_MAX, size);
	Node* root = bstFromPreorder4(pre, size);
	inorder(root);

	return 0;
}