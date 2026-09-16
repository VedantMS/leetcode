class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp, first;
        int ans = 0, degree = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (first.count(nums[i]) == 0) {
                first[nums[i]] = i;
            }

            mp[nums[i]]++;

            if (mp[nums[i]] > degree) {
                degree = mp[nums[i]];
                ans = i - first[nums[i]] + 1;
            }

            else if (mp[nums[i]] == degree) {
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }

        return ans;
    }
};