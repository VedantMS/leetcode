class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = 0;

            while (nums[i]) {
                num += nums[i] % 10;
                nums[i] /= 10;
            }

            if (num == i) {
                return i;
            }
        }

        return -1;
    }
};