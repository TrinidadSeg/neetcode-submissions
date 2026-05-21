class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> letters;
        int l = 0;
        int r = 0;
        int rml = 0;
        while (r < s.size()) {
            letters[s[r]]++;
            while (letters[s[r]] > 1) {
                letters[s[l]]--;
                l++;
            }
            rml = max(rml, r - l + 1);
            r++;
        }
        return rml;
    }
};
