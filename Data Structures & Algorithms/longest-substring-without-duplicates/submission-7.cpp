class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> letters;
        int l = 0;
        int r = 0;
        int rml = s.empty() ? 0 : 1;
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
