class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int mn = 1, mx = 1;

        for (int num : nums) {
            int temp = mx * num;
            mx = max({temp, mn * num, num});
            mn = min({temp, mn * num, num});

            ans = max(ans, mx);
        }

        return ans;
    }
};