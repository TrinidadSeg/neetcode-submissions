class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> frq;
        for (int i: nums) frq.insert(i);
        return frq.size() != nums.size();

    }
};