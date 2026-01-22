class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int[] right_sum = new int[n];
        int sum = 0;
        right_sum[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            right_sum[i] = right_sum[i + 1] + nums[i + 1];
        }
        for(int i = 0; i < n; i++) {
            if(sum == right_sum[i]) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
}