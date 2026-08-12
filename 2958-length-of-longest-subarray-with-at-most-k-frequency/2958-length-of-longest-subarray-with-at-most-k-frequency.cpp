class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, ct = 0, index = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            ct++;

            while (index < i && mp[nums[i]] > k) {
                mp[nums[index]]--;
                index++;
                ct--;
            }

            ans = max(ans, ct);
        }

        return ans;
    }
};