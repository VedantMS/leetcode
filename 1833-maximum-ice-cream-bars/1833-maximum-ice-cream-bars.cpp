class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> a(100001, 0);

        for (int &coin : costs) {
            a[coin]++;
        }

        int ans = 0;

        for (int i = 1; i < 100001; i++) {
            if (a[i] > 0) {
                if (i > coins) {
                    break;
                }

                int ice_cream = min(a[i], coins / i);

                ans += ice_cream;

                coins -= ice_cream * i;
            }
        }

        return ans;
    }
};