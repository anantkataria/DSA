class Solution {
public:
    bool isOperand(string s){
        if(s.size() > 1){
            if(s[0] == '-')
                return true;
        }
        if(s[0] >= '0' && s[0] <= '9')
                return true;   
        return false;
    }
    
    int convertToInt(string s){
        bool isNegative = false;
        int start = 0;
        if(s[0] == '-'){
            isNegative = true;
            start++;
        }
        
        int ans = 0;
        for(int i=start; i<s.size(); i++){
            ans = ans*10 + (s[i] - '0');
        }
        if(isNegative)
            ans*=(-1);
        return ans;
    }
    
    int doOperation(int a, int b, string operatr){
        int ans = 0;
        if(operatr == "+"){
            ans = a+b;
        }
        else if(operatr == "-"){
            ans = a-b;
        }
        else if(operatr == "/"){
            ans = a/b;
        }
        else if(operatr == "*"){
            ans = a*b;
        }
        return ans;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        
        for(int i=0; i<tokens.size(); i++){
            if(isOperand(tokens[i])){
                operands.push(convertToInt(tokens[i]));
            }
            else {
                int v2 = operands.top(); operands.pop();
                int v1 = operands.top(); operands.pop();
                operands.push(doOperation(v1, v2, tokens[i]));
            }
        }
        
        return operands.top();
    }
};