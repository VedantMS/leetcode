class Solution {
public:
    bool isThree(int n) {
        int ans = 2;

        if (n < 4) {
            return false;
        }

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                ans++;
            } 
        }

        return ans == 3;
    }
};