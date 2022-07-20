//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}
// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree

bool isOperand(char c){
    if(c >= 'a' && c <= 'z')
        return true;
    else 
        return false;
}
et* constructTree(char postfix[])
{
    stack<et*> s;
    int i=0;
    while(postfix[i] != '\0'){
        et* temp = new et(postfix[i]);
        if(isOperand(postfix[i])){
            s.push(temp);
        }
        else if(isOperator(postfix[i])){
            et* b = s.top(); s.pop();
            et* a = s.top(); s.pop();
            temp -> left = a;
            temp -> right = b;
            s.push(temp);
        }
        i++;
    }
    return s.top();
}
