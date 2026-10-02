class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if (n % 2) {
            return false;
        }

        int num = 0;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') {
                num++;
            }

            else {
                num--;
            }

            if (num < 0) {
                return false;
            }
        }

        num = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') {
                num++;
            }

            else {
                num--;
            }

            if (num < 0) {
                return false;
            }
        }

        return true;
    }
};