class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 1) return {{}, nums};
        vector<int> rest(nums.begin()+1, nums.end());
        vector<vector<int>> bt = subsets(rest);
        int len = bt.size();
        for (int i = 0; i < len; i++) {
            vector<int> temp = bt[i];
            temp.push_back(nums[0]);
            bt.push_back(temp);
        }
        return bt;
    }

};
