class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l+(r-l)/2;
            int mn = nums[mid];
            if (mn < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
        
    }
};
