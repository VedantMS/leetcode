class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }

        if (n == 3) {
            return 2;
        }

        int num = n / 3, r = n % 3;

        if (r == 1) {
            num--;
            r = 4;
        }

        else if (r == 0) {
            r = 1;
        }

        return pow(3, num) * r;
    }
};