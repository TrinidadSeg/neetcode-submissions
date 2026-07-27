class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int m = 0;
        while (l < r) {
            int width = r - l;
            if (heights[l] > heights[r]) {
                m = max(m, width * heights[r]);
                r--;
            }
            else {
                m = max(m, width * heights[l]);
                l++;
            }
        }
        return m;
        
    }
};
