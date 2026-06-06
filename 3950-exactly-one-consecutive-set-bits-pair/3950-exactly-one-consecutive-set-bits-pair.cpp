class Solution {
public:
    bool consecutiveSetBits(int n) {
        int ans = n & (n >> 1);

        return ans > 0 && (ans & (ans - 1)) == 0;
    }
};