class Solution {
public:

    vector<vector<int>> ans;
    int n;

    void helper(vector<int> &nums, vector<int> &cur, int curSum, int &target, int index) {
        if (curSum == target) {
            ans.push_back(cur);
            return;
        }
        for (int i = index; i < n; i++) {
            if (nums[i] <= target - curSum) {
                cur.push_back(nums[i]);
                helper(nums, cur, curSum + nums[i], target, i);
                cur.pop_back();
            }
            else return;
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        n = nums.size();
        sort(nums.begin(), nums.end());
        helper(nums, cur, 0, target, 0);
        return ans;
    }
};
