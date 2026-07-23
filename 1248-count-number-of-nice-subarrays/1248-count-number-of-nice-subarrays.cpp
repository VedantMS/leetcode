class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, index = 0, count = 0, n = nums.size();

        for (int &num : nums) {
            if (num & 1) {
                k--;
                count = 0;
            }

            while (k == 0) {
                k += nums[index++] & 1;
                ++count;
            }

            ans += count;
        }

        return ans;
    }
};