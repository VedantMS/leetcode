class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        int i = 0, j = 0;
        while(i < rows) {
            j = 0;
            while(j < cols) {
                if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    if(grid[i][j] == 1) {
                        dfs(grid, i, j);
                    }
                }
                j++;
            }
            i++;
        }
        for(i = 1; i < rows - 1; i++) {
            for(j = 1; j < cols - 1; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};