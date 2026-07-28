class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int lcur = 0;
        int rcur = 0;
        int ar = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                lcur = max(height[l], lcur);
                ar -= height[l] - lcur;
                cout<<ar<<endl;
                l++;
            }
            else {
                rcur = max(height[r], rcur);
                ar -= height[r] - rcur;
                cout<<ar<<endl;
                r--;
            }

        }
        return ar;
        
    }
};
