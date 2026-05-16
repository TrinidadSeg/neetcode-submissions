class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int curMaxHeight = 0;
        int curArea = 0;
        while (l <= r) {
            if (height[l] < height[r]) {
                int curHeight = height[l];
                if (curHeight < curMaxHeight) {
                    curArea += curMaxHeight - height[l];
                    l++;
                }
                else {
                    curMaxHeight = curHeight;
                    l++;
                }
            }
            else {
                int curHeight = height[r];
                if (curHeight < curMaxHeight) {
                    curArea += curMaxHeight - height[r];
                    r--;
                }
                else {
                    curMaxHeight = curHeight;
                    r--;
                }

            }
        }
        return curArea;
        
    }
};
