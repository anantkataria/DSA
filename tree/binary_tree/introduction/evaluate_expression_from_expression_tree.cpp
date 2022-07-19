#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	Node* left;
	Node* right;
	Node(char k){
		data = k;
		left = right = NULL;
	}
};

Node* addNewNode(char k){
	Node* temp = new Node(k);
	return temp;
}

bool isOperand(char a){
	if(a >= '0' && a <= '9')
		return true;
	return false;
}

int calculate(int a, int b, char op){
	int ans = 0;
	switch(op){
		case '+': ans = a + b; break;
		case '-': ans = a - b; break;
		case '*': ans = a * b; break;
		case '/': ans = a / b; break;
	}
	return ans;
}

int evaluateExpression(Node* root){
	if(!root)
		return 0;
	if(isOperand(root->data)){
		return (root->data) - '0';
	}
	int a = evaluateExpression(root->left);
	int b = evaluateExpression(root->right);
	return calculate(a, b, root->data);
}

int main() {
	Node* root = addNewNode('+');
	root -> left = addNewNode('3');
	root -> right = addNewNode('*');
	root -> right -> left = addNewNode('+');
	root -> right -> left -> left = addNewNode('5');
	root -> right -> left -> right = addNewNode('9');
	root -> right -> right = addNewNode('2');
	cout << evaluateExpression(root);
	return 0;
}