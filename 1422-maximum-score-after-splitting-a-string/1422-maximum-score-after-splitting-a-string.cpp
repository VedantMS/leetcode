class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;

        for (auto &ch : s) {
            ones += (ch == '1');
        }

        int zeros = 0, ans = 0;

        for (int i = 0; i < n - 1; i++) {
            zeros += (s[i] == '0');
            ones -= (s[i] == '1');

            ans = max(ans, zeros + ones);
        }

        return ans;
    }
};