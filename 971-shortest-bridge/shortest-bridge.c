int **queue;
int front, rear;

void island(int** grid, int n, int r, int c) {
    grid[r][c] = 2;
    queue[rear][0] = r;
    queue[rear][1] = c;
    rear++;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 1) {
            island(grid, n, nr, nc);
        }
    }
}

int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int flips = 0;

    queue = (int **)malloc(n * n * sizeof(int *));
    for(int  i = 0; i < n * n; i++) {
        queue[i] = (int *)malloc(2 * sizeof(int));
    }
    front = 0;
    rear = 0;

    bool flag = 0;
    for(int i = 0; i < n && !flag; i++) {
        for(int j = 0; j < n && !flag; j++) {
            if(grid[i][j] == 1) {
                island(grid, n, i, j);
                flag = 1;
            }
        }
    }

    while(front < rear) {
        int level = rear - front;

        for(int i = 0; i < level; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] != 2) {
                    if(grid[nr][nc] == 1) {
                        return flips;
                    }
                    grid[nr][nc] = 2;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                }
            }
        }
        flips++;
    }
    return flips;
}