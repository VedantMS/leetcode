class Solution {
public:
    string toHex(int num) {
        string ans = "";
        string hex = "0123456789abcdef";

        if (num == 0) {
            return "0";
        }

        unsigned int n = (unsigned int) num;

        while (n) {
            int index = n % 16;
            n /= 16;

            ans = hex[index] + ans;
        }

        return ans;
    }
};