class Solution {
public:
    string removeOuterParentheses(string s) {
        int num = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                num++;
                
                if (num > 1) {
                    ans += '(';
                }
            }

            else {
                if (num > 1) {
                    ans += ')';
                }

                num--;
            }
        }

        return ans;
    }
};