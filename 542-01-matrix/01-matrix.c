/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matSize;
    int cols = *matColSize;
    int **result;

    *returnSize = rows;
    *returnColumnSizes = (int *)malloc(rows * sizeof(int));

    result = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    if(rows == 1 && cols == 1) {
        result[0][0] = 0;
        return result;
    }

    int queue[rows * cols][2];
    int front = 0, rear = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] == 0) {
                result[i][j] = 0;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else {
                result[i][j] = -1;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(front < rear) {
        int level = rear - front;

        for(int i = 0; i < level; i++) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for(int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && result[nr][nc] == -1) {
                    result[nr][nc] = result[r][c] + 1;
                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                }
            }
        }
    }
    return result;
}