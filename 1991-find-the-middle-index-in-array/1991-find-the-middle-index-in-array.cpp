class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if ((i == 0 ? 0 : nums[i - 1]) == (i == n - 1 ? 0 : nums[n - 1] - nums[i])) {
                return i;
            }
        }

        return -1;
    }
};