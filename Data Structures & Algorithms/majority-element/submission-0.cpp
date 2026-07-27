class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int frq = 0;
        for (int i: nums) {
            if (i == frq) c++;
            else c--;
            if (c < 0) {frq = i; c=0;}
        }
        return frq;
    }
};