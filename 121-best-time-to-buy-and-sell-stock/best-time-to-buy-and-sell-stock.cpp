class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = 0;

        for(int price : prices) {
            if(min > price)         min = price;
            else if(min < price)    max = max > price - min ? max : price - min;
        }

        return max;
    }
};