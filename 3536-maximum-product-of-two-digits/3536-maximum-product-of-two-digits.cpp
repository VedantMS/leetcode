class Solution {
public:
    int maxProduct(int n) {
        int a = 0, b = 0;

        while (n) {
            int num = n % 10;
            n /= 10;

            if (num >= a) {
                b = a;
                a = num;
            }

            else if (num >= b) {
                b = num;
            }
        }

        return a * b;
    }
};