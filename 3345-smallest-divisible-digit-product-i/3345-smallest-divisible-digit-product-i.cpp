class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n, ans;
        
        while (num <= n + 10) {
            int temp = num, prod = 1;

            while (temp) {
                prod *= temp % 10;
                temp /= 10;
            }

            if (prod % t == 0) {
                ans = num;
                break;
            }

            num++;
        }

        return ans;
    }
};