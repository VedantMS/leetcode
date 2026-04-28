class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        
        dp[0] = true;

        for(int i = 1; i <= n; i++) {
            for(string &w : wordDict) {
                int start = i - w.length();

                if(start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};