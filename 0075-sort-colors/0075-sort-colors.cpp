class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0};

        for (int &num : nums) {
            a[num]++;
        }

        for (int &num : nums) {
            if (a[0] > 0) {
                num = 0;
                a[0]--;
            }

            else if (a[1] > 0) {
                num = 1;
                a[1]--;
            }

            else {
                num = 2;
                a[2]--;
            }
        }
    }
};