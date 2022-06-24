// https://gist.github.com/mycodeschool/7867739

//operator and operands both must be a single character

#include<bits/stdc++.h>
using namespace std;

string infixToPostfix(string expression);
bool isOperator(char c);
bool hasHigherPrecedence(char op1, char op2);
int getOperatorWeight(char op);
bool isRightAssociative(char op);
bool isOperand(char c);

int main() {
	string expression;
	getline(cin, expression);
	cout << infixToPostfix(expression);
	return 0;
}

string infixToPostfix(string expression){
	stack<char> s;
	string postfix = "";

	for(int i=0; i<expression.size(); i++){
		if(expression[i] == ' ' || expression[i] == ',')
			continue;

		else if(isOperator(expression[i])){
			while(!s.empty() && s.top()!='(' && hasHigherPrecedence(s.top(), expression[i])){
				postfix += s.top();
				s.pop();
			}
			s.push(expression[i]);
		}

		else if(isOperand(expression[i])){
			postfix += expression[i];
		}

		else if(expression[i] == '('){
			s.push(expression[i]);
		}

		else if(expression[i] == ')'){
			while(!s.empty() && s.top()!='('){
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
	}

	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}

	return postfix;
}

bool isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}

bool hasHigherPrecedence(char op1, char op2){
	int op1weight = getOperatorWeight(op1);
	int op2weight = getOperatorWeight(op2);

	if(op1weight == op2weight){
		if(isRightAssociative(op1)) return false;
		else return true;
	}

	return op1weight > op2weight ? true : false;
}

int getOperatorWeight(char op){
	int weight = -1;
	switch(op){
		case '+':
		case '-': 
				weight = 1;
				break;
		case '*':
		case '/':
				weight = 2;
				break;
		case '^':
				weight = 3;
				break;
	}
	return weight;
}

bool isRightAssociative(char op){
	if(op == '^')
		return true;
	return false;
}

bool isOperand(char c){
	if(c >= 'a' && c <= 'z') return true;
	else if (c >= 'A' && c <= 'Z') return true;
	else if (c >= '0' && c <= '9') return true;
	return false;
}