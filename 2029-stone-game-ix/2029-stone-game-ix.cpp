class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> a(3, 0);

        for (int &stone : stones) {
            a[stone % 3]++;
        }

        if (a[0] % 2 == 0) {
            return a[1] > 0 && a[2] > 0;
        }

        return abs(a[1] - a[2]) > 2;
    }
};