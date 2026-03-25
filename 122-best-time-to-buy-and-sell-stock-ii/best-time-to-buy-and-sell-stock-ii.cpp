class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int ans = 0;
        
        int n = prices.size();

        for(int i = 1; i <  n; i++) {
            if(min < prices[i]) {
                ans += prices[i] - min;
                min = prices[i];
            }

            else if(min > prices[i]) {
                min = prices[i];
            }
        }

        return ans;
    }
};