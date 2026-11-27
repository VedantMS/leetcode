class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> a(101, 0);

        for (int &num : nums) {
            a[num]++;
        }

        int ans = 0;

        for (int &num : a) {
            if (num > 1) {
                ans += (num * (num - 1)) / 2;
            }
        }

        return ans;
    }
};