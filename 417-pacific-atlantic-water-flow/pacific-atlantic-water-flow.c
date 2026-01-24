/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **pacific;
int **atlantic;

void dfs(int** heights, int rows, int cols, int **visited, int r, int c) {
    if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c])    return;

    visited[r][c] = 1;
    
    if(c - 1 >= 0 && heights[r][c] <= heights[r][c - 1])        dfs(heights, rows, cols, visited, r, c - 1);    // Left
    if(c + 1 < cols && heights[r][c] <= heights[r][c + 1])      dfs(heights, rows, cols, visited, r, c + 1);    // Right
    if(r - 1 >= 0 && heights[r][c] <= heights[r - 1][c])        dfs(heights, rows, cols, visited, r - 1, c);    // Up
    if(r + 1 < rows && heights[r][c] <= heights[r + 1][c])      dfs(heights, rows, cols, visited, r + 1, c);    // Down
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int rows = heightsSize;
    int cols = *heightsColSize;
    *returnSize = 0;
    
    pacific = (int **)malloc(rows * sizeof(int *));
    atlantic = (int **)malloc(rows * sizeof(int *));
    int **res = (int **)malloc(rows * sizeof(int *));
    
    for(int i = 0; i < rows; i++) {
        pacific[i] = (int *)calloc(cols, sizeof(int));
        atlantic[i] = (int *)calloc(cols, sizeof(int));
        res[i] = (int *)calloc(cols, sizeof(int));
    }
    
    for(int i = 0; i < cols; i++)   dfs(heights, rows, cols, pacific, 0, i), dfs(heights, rows, cols, atlantic, rows - 1, i);
    for(int i = 0; i < rows; i++)   dfs(heights, rows, cols, pacific, i, 0), dfs(heights, rows, cols, atlantic, i, cols - 1);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(pacific[i][j] && atlantic[i][j]) {
                res[i][j] = 1;
                (*returnSize)++;
            }
        }
    }
    int **result = (int **)malloc((*returnSize) * sizeof(int *));
    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
    int index = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(res[i][j] == 1) {
                result[index] = (int *)malloc(2 * sizeof(int));
                (*returnColumnSizes)[index] = 2;
                result[index][0] = i;
                result[index++][1] = j;
            }
        }
    }

    free(pacific);
    free(atlantic);
    free(res);
    
    return result;
}