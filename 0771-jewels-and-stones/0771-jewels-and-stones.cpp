class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> a(26, false), A(26, false);

        for (char &jewel : jewels) {
            if (jewel >= 'a') {
                a[jewel - 'a'] = true;
            }

            else {
                A[jewel - 'A'] = true;
            }
        }

        int ans = 0;

        for (char &stone : stones) {
            if (stone >= 'a') {
                if (a[stone - 'a']) {
                    ans++;
                }
            }

            else {
                if (A[stone - 'A']) {
                    ans++;
                }
            }
        }

        return ans;
    }
};