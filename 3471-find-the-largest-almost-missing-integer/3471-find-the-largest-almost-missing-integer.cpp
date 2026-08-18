class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> a(51, 0);
        int mx = -1;

        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]]++;
        }

        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (a[i] == 1) {
                    return i;
                }
            }
        }

        if (k == nums.size()) {
            for (int i = 50; i >= 0; i--) {
                if (a[i]) {
                    return i;
                }
            }
        }

        int ans = -1;

        if (a[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (a[nums[nums.size() - 1]] == 1) {
            ans = max(ans, nums[nums.size() - 1]);
        }

        return ans;
    }
};