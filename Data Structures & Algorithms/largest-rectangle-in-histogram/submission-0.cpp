class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && heights[i] < st.top().first) {
                int height = st.top().first;
                int index = st.top().second;
                st.pop();

                maxArea = max(maxArea, height * (i - index));
                start = index; // extend current bar leftward
            }

            st.push({heights[i], start});
        }

        // process remaining bars
        while (!st.empty()) {
            int height = st.top().first;
            int index = st.top().second;
            st.pop();

            maxArea = max(maxArea,
                          height * ((int)heights.size() - index));
        }

        return maxArea;
    }
};