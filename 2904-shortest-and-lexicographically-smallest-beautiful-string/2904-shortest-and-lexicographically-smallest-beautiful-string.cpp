class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), num = 0, left = 0, right = 0;
        string ans = "";

        for (right = 0; right < n; right++) {
            num += s[right] == '0' ? 0 : 1;

            while (num > k) {
                num -= s[left++] == '0' ? 0 : 1;
            }

            if (num == k) {
                while (left < right && s[left] == '0') {
                    left++;
                }

                string str = s.substr(left, right - left + 1);

                if (ans == "" || str.size() < ans.size() || (str.size() == ans.size() && str < ans)) {
                    ans = str;
                }
            }
        }

        return ans;
    }
};