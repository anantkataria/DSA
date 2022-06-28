#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

// Array version

// class Stack {
// 	int top;
// public:
// 	int a[MAX]; // Maximum size of stack

// 	Stack() {top = -1;}
// 	bool push(int x);
// 	int pop();
// 	int peek();
// 	bool isEmpty();
// };

// bool Stack::push(int x){
// 	if(top >= (MAX - 1)){
// 		cout << "Stack overflow\n";
// 		return false;
// 	}
// 	else {
// 		a[++top] = x;
// 		cout << x << " pushed into stack\n";
// 		return true;
// 	}
// }

// int Stack::pop() {
// 	if(top < 0){
// 		cout << "Stack underflow\n";
// 		return 0;
// 	}
// 	else {
// 		int x = a[top--];
// 		return x;
// 	}
// }

// int Stack::peek() {
// 	if(top < 0){
// 		cout << "Stack is empty\n";
// 		return 0;
// 	}
// 	else {
// 		int x = a[top];
// 		return x;
// 	}
// }

// bool Stack::isEmpty() {
// 	return (top < 0);
// }

// int main() {
// 	Stack s;
// 	s.push(10);
// 	s.push(20);
// 	s.push(30);
// 	cout << s.pop() << " popped from stack\n";

// 	cout << "Top element is : " << s.peek() << endl;

// 	cout << "Elements present is stack : ";
// 	while(!s.isEmpty()){
// 		cout << s.peek() << " ";
// 		s.pop();
// 	}

// 	return 0;
// }

//Pros of array implementation : Easy to implement. Memory is saved as pointers are not involved.
//Cons : It is not dynamic. It doesn't grow and shrink depending on needs at runtime.


//-------------------------------------------------------------------------------------------------------------

//Stack using Linked List

class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data){
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(StackNode* root){
	return !root;
}

void push(StackNode** root, int data){
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << " pushed to stack\n";
}

int pop(StackNode** root){
	if(isEmpty(*root))
		return INT_MIN;
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp -> data;
	free(temp);

	return popped;
}

int peek(StackNode* root){
	if(isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main() {
	StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
   
   	cout << pop(&root) << " popped from stack\n";
  
    cout << "Top element is " << peek(root) << endl;
      
    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout<<peek(root)<<" ";
        // remove top element in stack
        pop(&root);
    }
  
    return 0;

}