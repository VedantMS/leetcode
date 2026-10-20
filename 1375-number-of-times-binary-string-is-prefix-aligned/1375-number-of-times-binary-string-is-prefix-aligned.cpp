class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int num = 0, ans = 0;

        for (int i = 0; i < flips.size(); i++) {
            num = max(num, flips[i]);

            if (num == i + 1) {
                ans++;
            }
        }

        return ans;
    }
};