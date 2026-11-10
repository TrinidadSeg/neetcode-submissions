class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int running = 0;
        for (int i: nums) running ^= i;
        return running;
    }
};
