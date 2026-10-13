class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int num = *max_element(nums.begin(), nums.end()), len = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                len++;
                ans = max(ans, len);
            }

            else {
                len = 0;
            }
        }

        return ans;
    }
};