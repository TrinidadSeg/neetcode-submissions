class Solution {
public:
    bool isValid(string s) {
        stack<int> p;
        for (char ch: s) {
            if (p.size() == 0) p.push(translate(ch));
            else if (translate(ch)/p.top() == 4) p.pop();
            else p.push(translate(ch));
        }
        return (p.size() == 0);
        
    }
    int translate(char c) {
        switch (c) {
            case '(': return 1;
            case ')': return 4;
            case '[': return 2;
            case ']': return 8;
            case '{': return 3;
            case '}': return 12;
        }
        return 0;
    }
};
