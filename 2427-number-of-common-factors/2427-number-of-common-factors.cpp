class Solution {
public:
    int commonFactors(int a, int b) {
        int num = min(a, b);
        int ans = 0;

        for (int i = 1; i <= num; i++) {
            if (a % i == 0 && b % i == 0) {
                ans++;
            }
        }

        return ans;
    }
};