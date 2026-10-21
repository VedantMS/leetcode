class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;

        for (int num : nums) {
            sum1 += num;

            while (num) {
                sum2 += num % 10;
                num /= 10;
            }
        }

        return sum1 - sum2;
    }
};