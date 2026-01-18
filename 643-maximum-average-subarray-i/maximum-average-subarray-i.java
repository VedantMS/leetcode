class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double avg = Integer.MIN_VALUE, temp = Integer.MIN_VALUE;
        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        temp = sum / k;
        avg = Math.max(avg, temp);
        for(int j = k; j < nums.length; j++) {
            sum -= nums[j - k];
            sum += nums[j];
            temp = sum / k;
            avg = Math.max(avg, temp);
        }
        return avg;
    }
}