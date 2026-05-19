class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            bool worked = iterate(piles, mid, h);
            if (worked) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool iterate(vector<int> piles, int limit, int h) {
        int counter = 0;
        for (int i: piles) {
            if (i % limit != 0) counter++;
            counter += i / limit;
        }
        return (counter <= h);
    }
};
