class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mn_cost = min(costBoth, cost1 + cost2), mn_need = min(need1, need2), ans = 0;

        ans = mn_cost * mn_need + (need1 - mn_need) * min(cost1, costBoth) + (need2 - mn_need) * min(cost2, costBoth);

        return ans;
    }
};