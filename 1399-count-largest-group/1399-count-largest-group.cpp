class Solution {
public:
    int group(int n) {
        int num = 0;

        while (n) {
            num += n % 10;
            n /= 10;
        }

        return num;
    }

    int countLargestGroup(int n) {
        vector<int> a(37);

        for (int i = 1; i <= n; i++) {
            a[group(i)]++;
        }

        int num = 0, ct = 0, ans = 0;

        for (int i = 0; i < 37; i++) {
            if (a[i] > ct) {
                num = i;
                ct = a[i];
                ans = 1;
            }

            else if (a[i] == ct) {
                ans++;
            }
        }

        return ans;
    }
};