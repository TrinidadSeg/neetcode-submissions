class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();

        if (windowSize > s2.size()) return false;

        vector<int> let(26, 0);

        for (char ch : s1) {
            let[ch - 'a']++;
        }

        int correct = 0;
        int l = 0, r = 0;

        while (r < windowSize) {
            if (let[s2[r] - 'a'] > 0) {
                correct++;
            }

            let[s2[r] - 'a']--;
            r++;
        }

        if (correct == windowSize) return true;

        while (r < s2.size()) {

            if (let[s2[l] - 'a'] >= 0) {
                correct--;
            }
            let[s2[l] - 'a']++;
            l++;

            if (let[s2[r] - 'a'] > 0) {
                correct++;
            }
            let[s2[r] - 'a']--;
            r++;

            if (correct == windowSize) return true;
        }

        return false;
    }
};