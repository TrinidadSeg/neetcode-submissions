class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1;
        int f2 = 1;
        if (!n) return 0;
        if (n == 1) return 1;
        for (int i = 1; i < n; i++) {
            int temp = f2;
            f2 = f1;
            f1 = f2 + temp;
        }
        return f1;
        
    }
};
