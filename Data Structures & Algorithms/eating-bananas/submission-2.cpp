class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() > h) return -1;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r-l)/2;
            bool done = iterate(piles, h, mid);
            if (done) r = mid;
            else l = mid + 1;
        }

        return l;
    }
    bool iterate(vector<int>& piles, int h, int t) {
        int counter = 0;
        for (int i: piles) {
            counter += (i+t-1)/t;
        }
        return (counter <= h);
    }
};
