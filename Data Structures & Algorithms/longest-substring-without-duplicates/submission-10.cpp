class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rml = s.empty() ? 0 : 1;
        unordered_map<char, int> frq;
        int l = 0; int r = 0;
        while (r < s.size()) {
            frq[s[r]]++;
            while (frq[s[r]] > 1) {
                frq[s[l]]--;
                l++;
            }
            rml = max(rml, r - l + 1);
            r++;
        }
        return rml;
    }
};
