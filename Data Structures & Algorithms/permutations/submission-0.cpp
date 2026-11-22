class Solution {
public:

    vector<vector<int>> ans;
    int n;
    void helper(vector<int> &nums, vector<int> &cur, vector<bool> &used) {
        bool check = true;
        for (bool b: used) check &= b;
        if (check) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            helper(nums, cur, used);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> cur;
        vector<bool> used(n);
        helper(nums, cur, used);
        return ans;
    }
};
