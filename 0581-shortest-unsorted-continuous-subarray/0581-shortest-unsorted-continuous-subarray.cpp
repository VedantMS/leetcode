class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), left = -1, right = -1, mn = INT_MAX, mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if (nums[i] < mx) {
                right = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);

            if (nums[i] > mn) {
                left = i;
            }
        }

        return left == -1 ? 0 : right - left + 1;
    }
};