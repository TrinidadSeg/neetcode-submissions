class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        int c = 0;
        int d = 0;
        for(int i: nums){
             if (i != val) {
                temp.push_back(i);
                c++;
             }
             d++;
        }
        for (int i = 0; i < d; i++) temp.push_back(0);
        nums = temp;
        return c;
    }
};