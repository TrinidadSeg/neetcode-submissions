class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ma = 0;
        int length = heights.size();
        stack<pair<int, int>> bars;
        for (int i = 0; i < length; i++) {
            int start = i;
            while (!bars.empty() && bars.top().first > heights[i]) {
                ma = max(ma, bars.top().first * (i - bars.top().second));
                start = bars.top().second;
                bars.pop();
            }
            bars.push({heights[i], start});
        }
        while (!bars.empty()) {
            ma = max(ma, bars.top().first * (length - bars.top().second));
            bars.pop();
        }
        return ma;
        
    }
};
