class Solution {
public:
    int area;
    int temp;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return;
        }
        
        grid[r][c] = 0;
        temp++;
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    temp = 0;
                    dfs(grid, i, j);
                    area = max(area, temp);
                }
            }
        }
        return area;
    }
};