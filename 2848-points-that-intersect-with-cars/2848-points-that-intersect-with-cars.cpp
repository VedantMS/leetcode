class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> prefix(102, 0);

        for (auto &num : nums) {
            prefix[num[0]]++;
            prefix[num[1] + 1]--;
        }

        int ans = 0;

        for (int i = 1; i < 102; i++) {
            prefix[i] += prefix[i - 1];

            if (prefix[i]) {
                ans++;
            }
        }

        return ans;
    }
};