class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> nums(10, 0);

        for (int &digit : digits) {
            nums[digit]++;
        }

        int n = digits.size(), ans = 0;

        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k += 2) {
                    ans +=  nums[i] > 0 &&
                            nums[j] > (i == j) &&
                            nums[k] > (i == k) + (j == k);
                }
            }
        }

        return ans;
    }
};