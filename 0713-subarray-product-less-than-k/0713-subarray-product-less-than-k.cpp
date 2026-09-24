class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int ans = 0, num = 1;

        for (int left = 0, right = 0; right < nums.size(); right++) {
            num *= nums[right];

            while (left <= right && num >= k) {
                num /= nums[left++];
            }

            ans += (right - left + 1);
        }

        return ans;
    }
};