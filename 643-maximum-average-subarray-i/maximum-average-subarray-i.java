class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double temp = 0;
        double sum = 0;
        for(int i = 0; i < k; i++) {
            temp += nums[i];
        }
        sum = temp;
        for(int j = k; j < nums.length; j++) {
            temp -= nums[j - k];
            temp += nums[j];
            sum = Math.max(sum, temp);
        }
        return sum / k;
    }
}