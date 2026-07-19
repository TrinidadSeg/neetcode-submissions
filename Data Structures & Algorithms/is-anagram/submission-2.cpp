class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.size();
        if (len != t.size()) return false;
        int letters[26] = {0};
        for (int i = 0; i < len; i++) {
            letters[s[i]-'a']++;
            letters[t[i]-'a']--;
        }
        for(int i: letters) if (i != 0) return false;
        return true;
    }
};
