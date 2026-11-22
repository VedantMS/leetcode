class Solution {
public:
    bool checkString(string s) {
        bool flag = false;

        for (char ch : s) {
            if (ch == 'a' && flag) {
                return false;
            }

            else if (ch == 'b') {
                flag = true;
            }
        }

        return true;
    }
};