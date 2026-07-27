class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = "";
        int n = 200;
        for (string s: strs) n = min<int>(n, s.size());
        for (int i = 0; i < n; i++) { 
            bool same = true;
            char check = strs[0][i];
            for (string s: strs) if (s[i] != check) same = false;
            if (same == false) return ans;
            else ans += check;
        }
        return ans;
    }
};