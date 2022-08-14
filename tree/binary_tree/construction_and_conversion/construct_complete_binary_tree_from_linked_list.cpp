#include<bits/stdc++.h>
using namespace std;

class LLNode {
public:
	int data;
	LLNode* next;
	LLNode(int data){
		this->data = data;
		next = NULL;
	}
};

LLNode* getNewLLNode(int data){
	LLNode* temp = new LLNode(data);
	return temp;
}

void push(LLNode** head, int data){
	LLNode* newNode = getNewLLNode(data);
	newNode->next = *head;
	*head = newNode;
}

void printLL(LLNode* head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
}

class BTNode {
public:
	int data;
	BTNode* left;
	BTNode* right;
	BTNode(int data){
		this -> data = data;
		left = right = NULL;
	}
};

BTNode* getNewBTNode(LLNode* head){
	BTNode* temp = new BTNode(head->data);
	return temp;
}

void convert(LLNode* head, BTNode* &root){

	if(!head){
		root = NULL;
		return;
	}

	root = getNewBTNode(head);
	head = head -> next;

	queue<BTNode*> q;
	q.push(root);

	while(head){
		BTNode* temp = q.front();q.pop();
		temp->left = getNewBTNode(head);
		q.push(temp->left);
		head = head -> next;
		if(head){
			temp->right = getNewBTNode(head);
			q.push(temp->right);
			head = head -> next;
		}
	}
}

void inorder(BTNode* root){
	if(!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


int main() {
	LLNode* head = NULL;
	push(&head, 36); //last node
	push(&head, 30);
	push(&head, 25);
	push(&head, 15);
	push(&head, 12);
	push(&head, 10); //first node

	// printLL(head);

	BTNode* root;
	convert(head, root);

	inorder(root);

	return 0;
}