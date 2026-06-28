class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        if (n == 1) {
            return 10;
        }

        int ans = 10;
        int num = 9;

        for (int i = 2; i <= n; i++) {
            num *= (10 - (i - 1));
            ans += num;
        }

        return ans;
    }
};