class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p = 0, n = 0, z = 0;

        for (int &num : nums) {
            if (num > 0) {
                p++;
            }

            else if (num < 0) {
                n++;
            }

            else {
                z++;
            }
        }

        if (z > 0) {
            return 0;
        }

        if (n % 2 == 0) {
            return 1;
        }

        return -1;
    }
};