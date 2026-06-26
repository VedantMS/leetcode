class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        for (int i = 2; i <= n; i++) {
            for (int j = 3; j >= 0; j--) {
                dp[j] += dp[j + 1];
            }
        }

        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};