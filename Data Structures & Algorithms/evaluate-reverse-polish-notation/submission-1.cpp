class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ops;
        for (string s: tokens) {
            int op = isOp(s);
            if (op == 0) ops.push(stoi(s));
            else {
                int n2 = ops.top();
                ops.pop();
                int n1 = ops.top();
                ops.pop();
                ops.push(operate(n1, n2, op));
            }
        }
        return ops.top();
    }
    int isOp(string s) {
        if (s == "+") return 1;
        else if (s == "-") return 2;
        else if (s == "*") return 3;
        else if (s=="/") return 4;
        else return 0;
    }
    int operate(int n1, int n2, int op) {
        if (op == 1) return n1 + n2;
        if (op == 2) return n1 - n2;
        if (op == 3) return n1 * n2;
        if (op == 4) return n1 / n2;
        return 0;
    }
};
