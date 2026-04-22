class Solution {
public:
    int reverseBits(uint32_t n) {
        int ans = 0;

        while(n) {
            ans += 1 << (31 - countr_zero(n));
            n &= n - 1;
        }

        return ans;
    }
};