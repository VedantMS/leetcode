void dfs(int **grid, int rows, int cols, int r, int c) {
    if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return;
    }
    grid[r][c] = 0;
    dfs(grid, rows, cols, r, c - 1);
    dfs(grid, rows, cols, r, c + 1);
    dfs(grid, rows, cols, r - 1, c);
    dfs(grid, rows, cols, r + 1, c);
}
int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;
    int ans = 0;
    int i = 0, j = 0;
    while(i < rows) {
        j = 0;
        while(j < cols) {
            if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                if(grid[i][j] == 1) {
                    dfs(grid, rows, cols, i, j);
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