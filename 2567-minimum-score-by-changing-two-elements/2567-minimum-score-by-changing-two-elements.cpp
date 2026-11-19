class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        int num1 = nums[n - 1] - nums[2];
        int num2 = nums[n - 2] - nums[1];
        int num3 = nums[n - 3] - nums[0];

        return min({num1, num2, num3});
    }
};