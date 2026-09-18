class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> prime(n + 1, true);
        int num = 0;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                num++;
            }
        }

        long long ans = 1;
        int a = 1e9 + 7;

        for (int i = 1; i <= num; i++) {
            ans = ((ans % a) * (i % a)) % a;
        }

        for (int i = 1; i <= n - num; i++) {
            ans = ((ans % a) * (i % a)) % a;
        }

        return ans;
    }
};