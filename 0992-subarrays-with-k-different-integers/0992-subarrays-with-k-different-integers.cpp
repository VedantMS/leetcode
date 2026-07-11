class Solution {
public:
    int subarray(vector<int> &nums, int n, int k) {
        vector<int> freq(n + 1, 0);
        int val = 0;

        int left = 0, right = 0;
        int ans = 0;

        while (right < n) {
            if (freq[nums[right]]++ == 0) {
                val++;
            }

            while (val > k) {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    val--;
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