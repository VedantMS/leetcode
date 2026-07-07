class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char &ch : s) {
            mp[ch]++;
        }

        int ones = 0, ans = 0;

        for (auto &[key, value] : mp) {
            if (value == 1) {
                ones++;
            }

            else if (value & 1) {
                ans += value - 1;
                ones++;
            }

            else {
                ans += value;
            }
        }

        if (ones > 0) {
            ans += 1;
        }

        return ans;
    }
};