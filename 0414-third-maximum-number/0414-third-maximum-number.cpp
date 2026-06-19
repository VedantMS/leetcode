class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        int n = nums.size();
        
        for (int &num : nums) {
            if (num == a || num == b || num == c) {
                continue;
            }

            if (a < num) {
                c = b;
                b = a;
                a = num;
            }

            else if (num > b) {
                c = b;
                b = num;
            }

            else if (num > c) {
                c = num;
            }
        }

        if (c == LLONG_MIN) {
            return a;
        }

        return c;
    }
};