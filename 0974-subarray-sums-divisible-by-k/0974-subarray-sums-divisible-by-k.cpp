class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), sum = 0, ans = 0;

        mp[0] = 1;

        for (int num : nums) {
            sum = ((sum + num) % k + k) % k;

            ans += mp[sum];

            mp[sum]++;
        }

        return ans;
    }
};