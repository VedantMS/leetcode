class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> a(101, 0);
        int ans = 0;

        for (int &num : nums) {
            a[num]++;
        }

        for (int &num : nums) {
            if (num + k <= 100) {
                ans += a[num + k];
            }
        }

        return ans;
    }
};