class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temps;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (temps.empty()) {
                temps.push({temperatures[i], i});
                continue;
            }
            while (!temps.empty() && temps.top().first < temperatures[i]) {
                ans[temps.top().second] = i - temps.top().second;
                temps.pop();
            }
            temps.push({temperatures[i], i});
        }
        return ans;
    }
};
