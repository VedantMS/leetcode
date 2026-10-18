class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num2 == 0) {
            return popcount((unsigned) num1);
        }

        long long num = num1;

        for (int i = 1; i < 36; i++) {
            num -= num2;

            if (num < i) {
                return -1;
            }

            if (num >= 0 && i >= popcount((unsigned long long) num)) {
                return i;
            }
        }

        return -1;
    }
};