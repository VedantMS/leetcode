class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int num = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                int a = nums[i];
                nums[i] = nums[num];
                nums[num] = a;
                num++;
            }
        }

        return nums;
    }
};