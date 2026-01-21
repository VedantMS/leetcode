class Solution {
public:
    int flag;
    int cells;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            flag = 1;
            return;
        }
        else if(grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        cells++;
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    flag = 0;
                    cells = 0;
                    dfs(grid, i, j);
                    if(flag != 1) {
                        ans += cells;
                    }
                }
            }
        }
        return ans;
    }
};