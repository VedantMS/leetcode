class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long num = INT_MAX;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int a = abs(prefix[i] / (i + 1) - (i < n - 1 ? (prefix[n - 1] - prefix[i]) / (n - i - 1) : 0));

            if (a < num) {
                num = a;
                ans = i;
            }
        }

        return ans;
    }
};