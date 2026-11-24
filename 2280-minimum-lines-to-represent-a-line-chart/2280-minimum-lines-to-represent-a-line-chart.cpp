class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size(), ans = n - 1;

        sort(stockPrices.begin(), stockPrices.end());

        for (int i = 1; i < n - 1; i++) {
            if (1LL * (stockPrices[i][0] - stockPrices[i - 1][0]) * (stockPrices[i + 1][1] - stockPrices[i][1]) == 1LL * (stockPrices[i + 1][0] - stockPrices[i][0]) * (stockPrices[i][1] - stockPrices[i - 1][1])) {
                ans--;
            }
        }

        return ans;
    }
};