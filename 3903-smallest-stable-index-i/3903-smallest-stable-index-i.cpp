class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);

        int mn = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            a[i] = mn;
        }

        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            
            if (mx - a[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};