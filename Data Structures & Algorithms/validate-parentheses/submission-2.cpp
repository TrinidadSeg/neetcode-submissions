class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for (int i = 0; i < s.size(); i++) {
            if (ans.empty()) ans.push(s[i]);
            else {
                if (matches(ans.top(), s[i])) ans.pop();
                else ans.push(s[i]);
            }
        }
        return (ans.empty());
        
    }
    bool matches(char a, char b) {
        if (a == '(' && b == ')') return true;
        else if (a == '[' && b == ']') return true;
        else if (a == '{' && b == '}') return true;
        else return false;
    }
};
