class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX, odd = 0;

        for (int &num : nums1) {
            mn = min(mn, num);

            if (num & 1) {
                odd++;
            }
        }

        if (mn & 1) {
            return true;
        }

        return odd == 0;
    }
};