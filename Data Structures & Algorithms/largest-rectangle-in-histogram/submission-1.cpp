class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> bars;
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!bars.empty() && heights[i] < bars.top().first) {
                maxArea = max(maxArea, bars.top().first * (i - bars.top().second));
                start = bars.top().second;
                bars.pop();
            }
            bars.push({heights[i], start});
        }
        int len = heights.size();
        while (!bars.empty()) {
            maxArea = max(maxArea, bars.top().first * (len - bars.top().second));
            bars.pop();
        }
        return maxArea;
    }
};
