class Solution {
public:

    vector<vector<int>> ans;
    int n;
    
    void helper(vector<int> &nums, vector<int> &cur, int remaining, int curIndex) {
        if (!remaining) {
            ans.push_back(cur);
            return;
        }
        if ((remaining < 0) || (curIndex >= n)) return;
        if (remaining >= nums[curIndex]) {
            cur.push_back(nums[curIndex]);
            helper(nums, cur, remaining - nums[curIndex], curIndex + 1);
            cur.pop_back();
            int counter = 0;
            while ((curIndex + counter < n) && (nums[curIndex] == nums[curIndex + counter])) counter++;
            helper(nums, cur, remaining, curIndex + counter);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        helper(candidates, cur, target, 0);
        return ans;
    }
};
