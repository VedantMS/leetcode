class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y, ans = 0;
        
        while (num) {
            num = num & num - 1;

            ans++;
        }

        return ans;
    }
};