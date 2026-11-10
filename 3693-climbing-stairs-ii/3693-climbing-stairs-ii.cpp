class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                int num = i - j;

                if (num < 0) {
                    break;
                }
            
                dp[i] = min(dp[i], dp[num] + costs[i - 1] + (i - num) * (i - num));
            }
        }

        return dp[n];
    }
};