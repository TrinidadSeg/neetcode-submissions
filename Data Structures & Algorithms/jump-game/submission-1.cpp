class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur_max = 0;
        for(int i = 0; i < n; i++) {
            cout<<"For an I val of " << i<<" my curmax is "<<cur_max<<endl;
            if (i > cur_max) return false;
            cur_max = max(cur_max, i + nums[i]);
            if (cur_max >= n - 1) return true;
        }   
        return true;
    }
};
