class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> seen;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (seen.empty() || seen.top().first >= temperatures[i]) seen.push({temperatures[i], i});
            else {
                while (!seen.empty() && temperatures[i] > seen.top().first) {
                    ans[seen.top().second] = i - seen.top().second;
                    seen.pop();
                }
                seen.push({temperatures[i], i});
            }
        }
        return ans;
    }
};
