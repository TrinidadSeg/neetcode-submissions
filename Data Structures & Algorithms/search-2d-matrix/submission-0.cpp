class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int width = matrix[0].size();
        int r = matrix.size() * width - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int mVal = matrix[mid / width][mid % width];
            if (mVal > target) r = mid - 1;
            else if (mVal < target) l = mid + 1;
            else return true;
        }
        return false;
        
    }
};
