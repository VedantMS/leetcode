int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = *gridColSize;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int perimeter = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                perimeter += 4;

                for(int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc]) {
                        perimeter--;
                    }
                }
            }
        }
    }

    return perimeter;
}