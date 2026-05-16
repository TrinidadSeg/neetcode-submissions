class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i: nums) cout<<i<<" ";
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int l = i+1;
            int r = nums.size() - 1;
            while (l < r) {
                int cur = nums[l]+nums[r];
                if (cur < target) {
                    l++;
                }
                else if (cur > target) {
                    r--;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (nums[l] == nums[l-1]) l++;
                    while (nums[r] == nums[r+1]) r--;
                }
            }
        }
        return ans;
    }
};
