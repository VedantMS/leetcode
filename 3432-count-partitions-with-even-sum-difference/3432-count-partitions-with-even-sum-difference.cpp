class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < n - 1; i++) {
            if (((2 * nums[i] - nums[n - 1]) % 2) == 0) {
                ans++;
            }
        }

        return ans;
    }
};