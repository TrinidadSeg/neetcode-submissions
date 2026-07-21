class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frq;
        vector<vector<int>> seen(nums.size() + 1);
        for (int i: nums) frq[i]++;
        for (auto& pair: frq) seen[pair.second].push_back(pair.first);
        int counter = 0;
        vector<int> ans;
        for (int i = nums.size(); i >= 1; i--) {
            cout<<seen[i].size()<<endl;
            if (seen[i].size() > 0) {
                for (int n: seen[i]) {
                    ans.push_back(n);
                    counter++;
                }
                if (counter == k) return ans;
            }
        }
        return {};
    }
};
