class Solution {
    public int minFlips(int a, int b, int c) {
        int ans = (a | b) ^ c;

        return Integer.bitCount(ans) + Integer.bitCount((a & b) & ans);
    }
}