class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0;
        int n = grid.length;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][0] == grid[0][j]) {
                    int k = 0;
                    while(k < n && grid[i][k] == grid[k][j]) {
                        k++;
                    }
                    if(k == n) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}