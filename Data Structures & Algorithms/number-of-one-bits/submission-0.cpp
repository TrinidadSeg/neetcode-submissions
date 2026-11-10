class Solution {
public:
    int hammingWeight(uint32_t n) {
        int running = 0;
        for (int i = 0; i < 32; i++) {
            running += (n & 1);
            n = n >> 1;
        }
        return running;

    }
};
