class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), num = 0;

        for (num = 0; num < n && nums[num]; num++);

        bool a = true, d = true;

        for (int i = 0; i < n; i++) {
            int next = nums[(i + 1) % n];

            if (next != (nums[i] + 1) % n) {
                a = false;
            }

            if (next != (nums[i] - 1 + n) % n) {
                d = false;
            }

            if (!a && !d) {
                return -1;
            }
        }

        return a ? min(num, n - num + 2) : min(num + 2, n - num);
    }
};