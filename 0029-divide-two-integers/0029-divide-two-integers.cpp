class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)        return INT_MAX;

        bool sign = (dividend > 0) == (divisor > 0);

        long long absDividend = abs(static_cast<long long> (dividend));
        long long absDivisor = abs(static_cast<long long> (divisor));

        long long ans = 0;

        while(absDividend >= absDivisor) {
            long long num = absDivisor;
            long long multiple = 1;

            while(absDividend >= (num << 1)) {
                num <<= 1;
                multiple <<= 1;
            }

            absDividend -= num;
            ans += multiple;
        }

        return sign ? ans : -ans;
    }
};