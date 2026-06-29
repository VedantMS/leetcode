class Solution {
public:
    int ans = 0;

    void sumways(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                ans++;
            }

            return;
        }

        sumways(nums, target, index + 1, sum + nums[index]);

        sumways(nums, target, index + 1, sum - nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        sumways(nums, target, 0, 0);

        return ans;
    }
};