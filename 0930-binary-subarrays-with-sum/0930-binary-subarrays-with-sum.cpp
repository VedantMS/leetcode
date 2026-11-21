class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        
        mp[0] = 1;

        for (int num : nums) {
            sum += num;

            if (mp.contains(sum - goal)) {
                ans += mp[sum - goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};