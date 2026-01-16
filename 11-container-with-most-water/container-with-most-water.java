class Solution {
    public int maxArea(int[] height) {
        int start = 0, end = height.length - 1, area = 0, temp = 0;
        while(start < end) {
            temp = Math.min(height[start], height[end]) * (end - start);
            if(area < temp) {
                area = temp;
            }
            area = Math.max(area, temp);
            if(height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }
        return area;
    }
}