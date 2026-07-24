class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = 0;

        for (int &num : nums) {
            n = max(n, num);
        }

        int u = 1;

        while (u <= n) {
            u <<= 1;
        }

        int len = nums.size();
        vector<int> s(u);

        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                s[nums[i] ^ nums[j]] = 1;
            }
        }

        vector<int> t(u);

        for (int i = 0; i < u; i++) {
            if (!s[i]) {
                continue;
            }

            for (int &num : nums) {
                t[i ^ num] = 1;
            }
        }

        int ans = 0;

        for (int i = 0; i < u; i++) {
            if (t[i]) {
                ans++;
            }
        }

        return ans;
    }
};