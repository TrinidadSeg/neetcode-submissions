class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for (int i: nums) seen.insert(i);
        vector<int> starts;
        for (int i : nums) if (!seen.count(i - 1)) starts.push_back(i);
        int maxLen = 0;
        for (int i: starts) {
            int len = 0;
            while (seen.count(i + len)) len++;
            maxLen = max(len, maxLen);
        }

        return maxLen;
        
    }
};
