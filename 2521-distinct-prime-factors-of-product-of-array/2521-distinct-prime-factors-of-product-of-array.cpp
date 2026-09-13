class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int mx = 0;

        for (int &num : nums) {
            mx = max(mx, num);
        }

        vector<bool> prime(mx + 1, true);

        for (int i = 2; i < mx + 1; i++) {
            if (prime[i]) {
                for (int j = 2; i * j <= mx + 1; j++) {
                    prime[i * j] = false;
                }
            }
        }        

        int ans = 0;

        for (int i = 2; i <= mx; i++) {
            if (prime[i]) {
                bool flag = false;

                for (int &num : nums) {
                    while (num % i == 0) {
                        num /= i;
                        flag = true;
                    }
                }

                if (flag) {
                    ans++;
                }
            }
        }

        return ans;
    }
};