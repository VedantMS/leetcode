class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        
        int ans = 0;
        for(int i = 0; i < points.length - 1; i++) {
            int dx = Math.abs(points[i][0] - points[i + 1][0]);   // Units to Traverse Horizontally
            int dy = Math.abs(points[i][1] - points[i + 1][1]);   // Units to Traverse Vertically
            ans += Math.max(dx, dy);
        }
        return ans;
    }
}

/* Chebyshev distance: 
    The minimum time to go from one point to the next.
    The maximum of the horizontal and vertical distances.
*/