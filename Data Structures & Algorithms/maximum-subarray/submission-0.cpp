class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefix(nums.size());
        int running_total = 0;
        for (int i = 0; i < nums.size(); i++) {
            running_total += nums[i];
            prefix[i] = running_total;
        }
        int cur_min = 0;
        int cur_best = INT_MIN;
        for (int i = 0; i < prefix.size(); i++) {
            cur_best = max(cur_best, prefix[i] - cur_min);
            cur_min = min(cur_min, prefix[i]);
        }
        return cur_best;
    }
};
