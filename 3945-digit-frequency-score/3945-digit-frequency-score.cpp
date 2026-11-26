class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        vector<int> a(10, 0);

        while (n) {
            a[n % 10]++;
            n /= 10;
        }

        for (int i = 0; i < 10; i++) {
            ans += i * a[i];
        }

        return ans;
    }
};