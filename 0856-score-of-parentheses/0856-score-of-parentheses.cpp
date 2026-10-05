class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, num = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                num++;
            }

            else {
                num--;

                if (s[i - 1] == '(') {
                    ans += 1 << num;
                }
            }
        }

        return ans;
    }
};