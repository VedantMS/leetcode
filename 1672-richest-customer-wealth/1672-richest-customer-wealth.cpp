class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (auto account : accounts) {
            int sum = 0;

            for (int num : account) {
                sum += num;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};