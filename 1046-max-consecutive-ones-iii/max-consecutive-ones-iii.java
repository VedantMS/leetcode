class Solution {
    public int longestOnes(int[] nums, int k) {
        int count = 0, ans = 0; 
        int no_of_zeros = 0;
        int start = 0, end = 0;
        while(end < nums.length) {
            count++;
            if(nums[end++] == 0) {
                no_of_zeros++;
            }
            if(no_of_zeros > k) {
                while(no_of_zeros > k) {
                    if(nums[start++] == 0) {
                        no_of_zeros--;
                    }
                    count--;
                }
            }
            ans = Math.max(ans, count);
        }
        return ans;
    }
}