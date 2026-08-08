class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r = rows * cols - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int mn = matrix[mid/cols][mid%cols];
            if (mn < target) l = mid + 1;
            else if (mn > target) r = mid - 1;
            else return true;
        }
        return false;
    }
};
