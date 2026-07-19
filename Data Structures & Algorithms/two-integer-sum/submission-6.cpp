class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int key = target - nums[i];
            if (seen.count(key)) return {seen[key], i};
            seen[nums[i]] = i;
        }
        return {0,0};
        
    }
};
