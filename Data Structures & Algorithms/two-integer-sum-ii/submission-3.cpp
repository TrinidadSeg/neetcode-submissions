class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r) {
            int lnum = numbers[l];
            int rnum = numbers[r];
            if (lnum + rnum < target) {
                l++;
                continue;
            }
            else if (lnum + rnum > target) {
                r--;
                continue;
            }
            return {l + 1, r + 1};
        }
        return {0,0};
        
    }
};
