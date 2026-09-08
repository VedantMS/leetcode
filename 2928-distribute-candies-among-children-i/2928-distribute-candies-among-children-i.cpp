class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;

        for (int i = 0; i <= limit; i++) {
            for (int j = 0; j <= limit; j++) {
                int sum = n - i - j;
                ans += sum <= limit && sum >= 0 ? 1 : 0;
            }
        }

        return ans;
    }
};