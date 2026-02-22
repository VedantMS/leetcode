int maxFish;
int tempFish;

void dfs(int **grid, int rows, int cols, int r, int c) {
    tempFish += grid[r][c];

    grid[r][c] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] > 0) {
            dfs(grid, rows, cols, nr, nc);
        }
    }
}

int findMaxFish(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;

    maxFish = 0;
    tempFish = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] > 0) {
                tempFish = 0;
                dfs(grid, rows, cols, i, j);
                if(maxFish < tempFish) {
                    maxFish = tempFish;
                }
            }
        }
    }

    return maxFish;
}