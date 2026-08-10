class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> frq(26, 0);
        int l = 0, maxCount = 0, maxLength = 0;

        for (int r = 0; r < s.size(); ++r) {
            // Add current character to frequency map and update max frequency in window
            frq[s[r] - 'A']++;
            maxCount = max(maxCount, frq[s[r] - 'A']);

            // If the number of replacements needed exceeds k, shrink from the left
            while ((r - l + 1) - maxCount > k) {
                frq[s[l] - 'A']--;
                l++;
            }

            // Track the maximum valid window size found
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};