class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int l = 0;
        int r = 0;
        int mlen = 0;
        while (r < s.size()) {
            seen[s[r]]++;
            while (seen[s[r]] > 1) {
                seen[s[l]]--;
                l++;
            }
            mlen = max(mlen, r-l+1);
            r++;
        }
        return mlen;
        
    }
};
