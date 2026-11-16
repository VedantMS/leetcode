class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int ans = 0;

        while (num != 1) {
            if (num % 2 == 0) {
                num >>= 1;
            }

            else if (num == 3 || (num & 3) == 1) {
                num--;
            }

            else {
                num++;
            }

            ans++;
        }

        return ans;
    }
};