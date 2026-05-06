class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            int res = 0;
            string currChar = tokens[i];
            if (currChar == "/" || currChar == "*" 
            || currChar == "+" || currChar == "-") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if (currChar == "/") {
                    res = num2 / num1; 
                } else if (currChar == "*"){
                    res = num2 * num1;
                } else if (currChar == "+"){
                    res = num2 + num1; 
                } else if (currChar == "-"){
                    res = num2 - num1;   
                }
                
                stk.push(res);
            } else {
                stk.push(stoi(currChar));
            }
        }

        return stk.top();
    }
};
