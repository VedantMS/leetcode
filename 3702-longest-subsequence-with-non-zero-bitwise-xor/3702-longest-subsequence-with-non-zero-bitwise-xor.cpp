class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int num = 0, nonzero = 0;

        for (int &n : nums) {
            nonzero |= n;
            num ^= n;
        }

        if (num != 0) {
            return nums.size();
        }

        if (nonzero) {
            return nums.size() - 1;
        }

        return 0;
    }
};