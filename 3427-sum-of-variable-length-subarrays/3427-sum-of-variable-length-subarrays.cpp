class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            
            if (i) {
                nums[i] += nums[i - 1];
            }

            int start = max(0, i - num);

            ans += nums[i] - (start > 0 ? nums[start - 1] : 0);
        }

        return ans;
    }
};