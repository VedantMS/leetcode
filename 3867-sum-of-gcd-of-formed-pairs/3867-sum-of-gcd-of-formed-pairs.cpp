class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;

        for (auto &num : nums) {
            mx = max(mx, num);
            num = gcd(mx, num);
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            ans += gcd(nums[i], nums[j]);
        }

        return ans;
    }
};