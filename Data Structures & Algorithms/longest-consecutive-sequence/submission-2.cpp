class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> starts;
        if (nums.size() == 0) return 0;
        for (int num: nums) {
            if (set.count(num - 1)) continue;
            starts.push_back(num);
        }
        int m = 1;
        for (int start: starts) {
            int counter = 1;
            while (set.count(start + counter)) {
                counter++;
            }
            m = max(m, counter);
        }
        return m;
    }
};
