class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0, ans = 0;

        for (char ch : s) {
            if (ch == '[') {
                open++;
            }
            
            else {
                if (open) {
                    open--;
                }

                else {
                    close++;
                }
            }
        }

        return (close + 1) / 2;
    }
};