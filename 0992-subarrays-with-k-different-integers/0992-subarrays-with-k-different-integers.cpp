class Solution {
public:
    int subarray(vector<int> &nums, int n, int k) {
        unordered_map<int, int> mp;

        int left = 0, right = 0;
        int ans = 0;

        while (right < n) {
            mp[nums[right]]++;

            while (mp.size() > k) {
                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                
                left++;
            }

            ans += right - left + 1;

            right++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        return subarray(nums, n, k) - subarray(nums, n, k - 1);
    }
};