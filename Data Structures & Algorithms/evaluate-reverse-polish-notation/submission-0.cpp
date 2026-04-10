class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        int result; 
        int op1;
        int op2;
        for( auto &s : tokens){
            if(s == "-"|| s== "+" || s== "/" || s== "*"){
                op2 = stoi(stk.top());
                stk.pop();
                op1 = stoi(stk.top());
                stk.pop();
                char op = s[0];
                switch(op){
                    case '-':
                    stk.push(to_string(op1-op2));
                    break;
                    case '+':
                    stk.push(to_string(op1+op2));
                    break;
                    case '*':
                    stk.push(to_string(op1*op2));
                    break;
                    case '/':
                    stk.push(to_string(op1/op2));
                    break;
                }
            }
            else{
                stk.push(s);
            }
        }
        return stoi(stk.top());
    }
};
