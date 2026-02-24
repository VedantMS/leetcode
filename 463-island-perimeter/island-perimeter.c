static const int dr[] = {-1, 1, 0, 0};
static const int dc[] = {0, 0, -1, 1};
int perimeter;

void dfs(int **grid, int rows, int cols, int r, int c) {
    grid[r][c] = 2;

    int count = 0;

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] > 0) {
            if(grid[nr][nc] == 1) {
                dfs(grid, rows, cols, nr, nc);
            }

            count++;
        }
    }

    perimeter += 4 - count;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;

    perimeter = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                dfs(grid, rows, cols, i, j);
                break;
            }
        }
    }

    return perimeter;
}