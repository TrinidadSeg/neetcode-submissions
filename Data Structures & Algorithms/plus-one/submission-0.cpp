class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size() + 1, 0);
        int rem = 1;
        for (int i = digits.size(); i > 0; i--) {
            ans[i] = (digits[i - 1] + rem) % 10;
            rem = (digits[i - 1] + rem) / 10;
        }
        if (rem) {
            ans[0] = rem;
            return ans;
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};
