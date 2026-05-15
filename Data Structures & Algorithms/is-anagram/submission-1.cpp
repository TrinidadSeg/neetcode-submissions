class Solution {
public:
    bool isAnagram(string s, string t) {
        int sl = s.length();
        if (sl != t.length()) return false;
        int l[26] = {0};
        for (int i = 0; i < sl; i++) {
            l[s[i]-'a']++;
            l[t[i]-'a']--;
        }
        for (int i: l) if (i != 0) return false;
        return true;
        
    }
};
