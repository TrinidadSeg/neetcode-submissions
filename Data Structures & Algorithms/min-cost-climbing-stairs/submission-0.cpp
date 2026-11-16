class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            int cur = minCost[i - 1] + cost[i - 1];
            if (i >= 2) {
                cur = min(cur, minCost[i - 2] + cost[i - 2]);
            }
            minCost[i] = cur;
        }
        return minCost[n];
    }
};
