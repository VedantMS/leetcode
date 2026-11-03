class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = ranges::max(nums), ans = 0;

        for (int num : nums) {
            ans += n - num;
        }

        return ans;
    }
};