int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int queue[mazeSize * (*mazeColSize)][2];
    int front = 0, rear = 0;
    int steps = 0;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    queue[rear][0] = entrance[0];
    queue[rear][1] = entrance[1];
    maze[entrance[0]][entrance[1]] = '+';
    rear++;

    while(front < rear) {
        int level = rear - front;
        for(int i = 0; i < level; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for(int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if(nr < mazeSize && nr >= 0 && nc < *mazeColSize && nc >= 0 && maze[nr][nc] == '.') {
                    if(nr == 0 || nr == mazeSize - 1 || nc == 0 || nc == *mazeColSize - 1) {
                        return steps + 1;
                    }
                    maze[nr][nc] = '+';
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