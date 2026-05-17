class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ops;
        for (int i = 0; i < tokens.size(); i++) { 
            if (isOperator(tokens[i])) {
                int l = ops.top();
                ops.pop();
                int f = ops.top();
                ops.pop();
                ops.push(operate(f, l, tokens[i]));
            }
            else ops.push(stoi(tokens[i]));
        }
        return ops.top();
        
    }
    bool isOperator(string s) {
        if (s == "+") return true;
        if (s == "-") return true;
        if (s == "*") return true;
        if (s == "/") return true;
        return false;
    }
    int operate(int f, int l, string op) {
        if (op == "+") return f + l;
        if (op == "-") return f - l;
        if (op == "*") return f * l;
        if (op == "/") return f / l;
        return 0;
    }
};
