class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int mn = nums[mid];
            if (mn == target) return mid;
            if (nums[l] <= mn) {
                if (target < mn && nums[l] <= target) r=mid-1;
                else l = mid+1;
            }
            else {
                if (target > mn && target <= nums[r]) l = mid+1;
                else r=mid-1;
            }
        }
        return -1;
        
    }
};
