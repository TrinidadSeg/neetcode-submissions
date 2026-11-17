class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            int counter = 0;
            int local = i;
            cout<<local<<endl;
            while (local) {
                if (local & 1) counter++;
                local /= 2;
            }
            ans[i] = counter;
        }
        return ans;
    }
};
