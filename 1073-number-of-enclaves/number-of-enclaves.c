int flag;
int count;
void dfs(int **grid, int rows, int cols, int r, int c) {
    if(r < 0 || r >= rows || c < 0 || c >= cols) {
        flag = 1;
        return;
    }
    else if(grid[r][c] == 0) {
        return;
    }
    grid[r][c] = 0;
    count++;
    dfs(grid, rows, cols, r, c - 1);
    dfs(grid, rows, cols, r, c + 1);
    dfs(grid, rows, cols, r - 1, c);
    dfs(grid, rows, cols, r + 1, c);
}
int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;
    int ans = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                flag = 0;
                count = 0;
                dfs(grid, rows, cols, i, j);
                if(!flag) {
                    ans += count;
                }
            }
        }
    }
    return ans;
}