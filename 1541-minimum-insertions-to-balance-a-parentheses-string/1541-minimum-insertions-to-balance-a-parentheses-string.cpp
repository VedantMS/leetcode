class Solution {
public:
    int minInsertions(string s) {
        int num = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                num++;
            }

            else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }

                else {
                    ans++;
                }

                if (num) {
                    num--;
                }

                else {
                    ans++;
                }
            }
        }

        return ans + num * 2;
    }
};