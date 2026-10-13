class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int &num : nums) {
            num = abs(num);
        }

        int n = nums.size();
        long long ans = 0;

        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        for (int i = 0; i < n / 2; i++) {
            ans -= nums[i] * nums[i];
        }

        for (int i = n / 2; i < n; i++) {
            ans += nums[i] * nums[i];
        }

        return ans;
    }
};