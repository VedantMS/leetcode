class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, num = 0;

        for (char ch : s) {
            if (ch == '(') {
                open++;
            }

            else if (open) {
                open--;
            }

            else {
                num++;
            }
        }

        return open + num;
    }
};