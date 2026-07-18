class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto num = minmax_element(nums.begin(), nums.end());

        int mn = *num.first, mx = *num.second;
        int ans;

        for (int i = 1; i <= mn; i++) {
            if (mn % i == 0 && mx % i == 0) {
                ans = i;
            }
        }

        return ans;
    }
};