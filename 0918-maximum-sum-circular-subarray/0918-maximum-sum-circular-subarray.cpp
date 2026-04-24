class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0, max_sum = nums[0], current_max = 0, min_sum = 0, current_min = 0;
        
        for(int i = 0; i < n; i++) {
            current_max = max(current_max + nums[i], nums[i]);
            max_sum = max(max_sum, current_max);

            current_min = min(current_min + nums[i], nums[i]);
            min_sum = min(min_sum, current_min);

            total += nums[i];
        }

        return max_sum > 0 ? max(max_sum, total - min_sum) : max_sum;
    }
};