class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int n = highLimit - lowLimit + 1;
        vector<int> a(46, 0);

        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0, num = i;

            while (num) {
                sum += num % 10;
                num /= 10;
            }

            a[sum]++;
        }

        return ranges::max(a);
    }
};