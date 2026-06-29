class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long num = 1 << n;
        long long ans = nums[0];
        
        for (int i = 1; i < num; i++) {
            long long a = 1;

            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    a *= nums[j];
                }
            }

            ans = max(ans, a);
        }

        return ans;
    }
};