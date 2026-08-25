class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> a(101, false);

        for (int &num : nums) {
            a[num] = true;
        }

        int num = k, i = 1;

        while (num <= 100) {
            if (!a[num]) {
                return num;
            }

            num = k * i++;
        }

        return num;
    }
};