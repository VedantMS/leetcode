/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** dfs(int **graph, int graphSize, int *graphColSize, int *stack, int *top, int* returnSize, int** returnColumnSizes, int **arr, int vertex) {
    stack[++(*top)] = vertex;

    if(stack[*top] == graphSize - 1) {
        (*returnSize)++;
        
        arr = (int**)realloc(arr, *returnSize * sizeof(int *));
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int *));
        (*returnColumnSizes)[*returnSize - 1] = *top + 1;
        
        arr[*returnSize - 1] = (int *)malloc((*top + 1) * sizeof(int));
        for(int i = 0; i <= *top; i++) {
            arr[*returnSize - 1][i] = stack[i];
        }
    }
    else {
        for(int i = 0; i < graphColSize[vertex]; i++) {
        arr = dfs(graph, graphSize, graphColSize, stack, top, returnSize, returnColumnSizes, arr, graph[vertex][i]);
        }
    }
    (*top)--;
    return arr;
 }
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    int **arr = NULL;
    *returnColumnSizes = NULL;
    int stack[graphSize], top = -1;
    *returnSize = 0;
    arr = dfs(graph, graphSize, graphColSize, stack, &top, returnSize, returnColumnSizes, arr, 0);
    return arr;
}