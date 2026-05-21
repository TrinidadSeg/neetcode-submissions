class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSell = 0;
        int l = 0;
        int r = 0;
        while (r < prices.size() - 1) {
            r++;
            if (prices[r] < prices[l]) {
                l = r;
            }
            maxSell = max(maxSell, prices[r] - prices[l]);
        }
        return maxSell;
        
    }
};
