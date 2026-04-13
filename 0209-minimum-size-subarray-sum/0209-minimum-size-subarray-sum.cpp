class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int sum = 0;
        int ans = numeric_limits<int>::max();

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            while(sum >= target) {
                ans = min(ans, i - index + 1);
                sum -= nums[index];
                index++;
            }
        }

        if(ans == numeric_limits<int>::max())    return 0;

        return ans;
    }
};