class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> letters(26, 0);
        int l = 0;
        int r = 0;
        int rml = s.empty() ? 0 : 1;
        while (r < s.size()) {
            letters[s[r]-'A']++;
            while (!checkValid(letters, k)) {
                letters[s[l]-'A']--;
                l++;
            }
            rml = max(rml, r - l + 1);
            r++;
        }
        return rml;
        
    }
    bool checkValid(vector<int> frq, int k) {
        int mostFrq = 0;
        int sum = 0;
        for (int i: frq) {
            mostFrq = max(mostFrq, i);
            sum += i;
        }
        return (mostFrq + k >= sum);
    }
};
