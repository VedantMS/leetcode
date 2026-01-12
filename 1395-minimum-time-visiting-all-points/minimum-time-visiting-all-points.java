class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        
        int ans = 0;
        for(int i = 0; i < points.length - 1; i++) {
            int rows = Math.abs(points[i][0] - points[i + 1][0]);   // Rows to Traverse
            int cols = Math.abs(points[i][1] - points[i + 1][1]);   // Columns to Traverse
            ans = ans + Math.max(rows, cols);
        }
        return ans;
    }
}

/* Chebyshev distance: 
    The minimum time to go from one point to the next.
    The maximum of the horizontal and vertical distances.
*/