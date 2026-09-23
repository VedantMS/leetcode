class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), total = 0;

        for (int &num : nums) {
            total += num;
        }

        int num = total - x;

        if (num < 0) {
            return -1;
        }

        if (num == 0) {
            return n;
        }

        int left = 0, sum = 0, a = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (left <= right && sum > num) {
                sum -= nums[left++];
            }

            if (sum == num) {
                a = max(a, right - left + 1);
            }
        }

        return a == -1 ? -1 : n - a;
    }
};