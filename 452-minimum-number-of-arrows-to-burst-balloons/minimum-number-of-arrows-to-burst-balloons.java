class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int ans = 1;
        int previous = 0;

        for(int present = 1; present < points.length; present++) {
            if(points[present][0] > points[previous][1]) {
                ans++;
                previous = present;
            }
        }

        return ans;
    }
}