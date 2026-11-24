class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            long long p = 1, g = 0, l = 1;

            for (int j = i; j < n; j++) {
                p *= nums[j];

                if (p > 2520) {
                    break;
                }

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (p == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};