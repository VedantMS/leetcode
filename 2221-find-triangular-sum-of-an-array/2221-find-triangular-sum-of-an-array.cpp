class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                nums[j] += nums[j - 1];

                if (nums[j] > 9) {
                    nums[j] %= 10;
                }
            }
        }

        return nums[n - 1];
    }
};