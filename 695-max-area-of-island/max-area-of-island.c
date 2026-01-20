int area;
int temp;
void dfs(int **grid, int rows, int cols, int r, int c) {
    if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return;
    }
    grid[r][c] = 0;
    temp++;
    dfs(grid, rows, cols, r, c - 1);
    dfs(grid, rows, cols, r, c + 1);
    dfs(grid, rows, cols, r - 1, c);
    dfs(grid, rows, cols, r + 1, c);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    area = 0;
    int rows = gridSize;
    int cols = *gridColSize;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                temp = 0;
                dfs(grid, rows, cols, i, j);
                area = area < temp ? temp : area;
            }
        }
    }
    return area;
}