int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return -1;
    }
    if(n == 1) {
        return 1;
    }
    int queue[n * n][2];
    int front = 0, rear = 0;
    int steps = 1;
    
    grid[0][0] = 1;
    queue[0][0] = 0;
    queue[0][1] = 0;
    rear++;

    int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

    while(front < rear) {
        int level = rear - front;

        for(int i = 0; i < level; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for(int j = 0; j < 8; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] != 1) {
                    if(nr == n - 1 && nc == n - 1) {
                        return steps + 1;
                    }
                    grid[nr][nc] = 1;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                }
            }
        }
        steps++;
    }
    return -1;
}