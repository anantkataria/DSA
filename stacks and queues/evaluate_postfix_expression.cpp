#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string expression);

bool isOperator(char c);

bool isNumericDigit(char c);

int performOperation(int op1, int op2, char operation);

int main() {
	string expression;
	getline(cin, expression);
	// cout << expression;
	int result = evaluatePostfix(expression);
	cout << result;
	return 0;
}

int evaluatePostfix(string expression){
	stack<int> s;
	for(int i=0; i<expression.size(); i++){
		if(expression[i] == ' ' || expression[i] == ',')
			continue;

		if(isOperator(expression[i])){
			int operand2 = s.top(); s.pop();
			int operand1 = s.top(); s.pop();
			int result = performOperation(operand1, operand2, expression[i]);
			s.push(result);
		}
		else if(isNumericDigit(expression[i])){
			int operand = 0;
			while(i < expression.size() && isNumericDigit(expression[i])){
				operand = operand*10 + (expression[i] - '0');
				i++;
			}
			i--;
			s.push(operand);
		}
	}

	return s.top();
}

bool isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

bool isNumericDigit(char c){
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

int performOperation(int op1, int op2, char operation){
	if(operation == '+') return op1 + op2;
	else if(operation == '-') return op1 - op2;
	else if(operation == '*') return op1 * op2;
	else if(operation == '/') return op1 / op2;
	else cout << "unexpected operator" << endl;
	return -1;
} 