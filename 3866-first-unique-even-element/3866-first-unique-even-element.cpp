class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> a(101, 0);

        for (int &num : nums) {
            a[num]++;
        }

        for (int &num : nums) {
            if (a[num] == 1 && num % 2 == 0) {
                return num;
            }
        }

        return -1;
    }
};