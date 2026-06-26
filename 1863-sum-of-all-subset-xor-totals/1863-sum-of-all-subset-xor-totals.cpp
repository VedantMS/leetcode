class Solution {
public:
    int ans = 0;

    void subset(vector<int> &nums, int index, int num) {
        if (index == nums.size()) {
            ans += num;
            return;
        }

        subset(nums, index + 1, num);

        subset(nums, index + 1, num ^ nums[index]);
    }

    int subsetXORSum(vector<int>& nums) {
        subset(nums, 0, 0);

        return ans;
    }
};