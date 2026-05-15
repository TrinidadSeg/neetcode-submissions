class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        int l = 1;
        int r = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] *= l;
            ans [nums.size()-i-1] *= r;
            l *= nums[i];
            r *= nums[nums.size()-i-1];
        }
        return ans;

    }
};
