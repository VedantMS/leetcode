class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for (auto &num : nums) {
            sum += num;
        }

        long long prefix = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            prefix += nums[i];

            if (prefix >= sum - prefix) {
                ans++;
            }
        }

        return ans;
    }
};