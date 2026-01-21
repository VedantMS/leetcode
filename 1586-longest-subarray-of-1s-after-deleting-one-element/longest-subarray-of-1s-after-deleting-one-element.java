class Solution {
    public int longestSubarray(int[] nums) {
        int start = 0;
        int no_of_zeros = 0;
        int ans = 0;
        for(int end = 0; end < nums.length; end++) {
            if(nums[end] == 0) {
                no_of_zeros++;
            }
            if(no_of_zeros > 1) {
                while(no_of_zeros > 1) {
                    if(nums[start++] == 0) {
                        no_of_zeros--;
                    }
                }
            }
            ans = Math.max(ans, end - start + 1 - no_of_zeros);
        }
        return ans == nums.length ? --ans : ans;
    }
}