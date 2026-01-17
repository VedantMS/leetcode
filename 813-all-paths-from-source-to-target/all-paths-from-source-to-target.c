/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **result;
int *rcs;
int rs;
int stack[15];
int top;

void  dfs(int** graph, int graphSize, int* graphColSize, int vertex) {
    stack[++top] = vertex;
    if(vertex == graphSize - 1) {
        int len = top + 1;
        result[rs] = (int *)malloc(len * sizeof(int));
        for(int i = 0; i < len; i++) {
            result[rs][i] = stack[i];
        }
        rcs[rs++] = len;
    }
    else {

        for(int i = 0; i < graphColSize[vertex]; i++) {
            dfs(graph, graphSize, graphColSize, graph[vertex][i]);
        }
    }
    top--;
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    int maximum_possible_paths = pow(2, 15);
    result = (int **)malloc(maximum_possible_paths * sizeof(int*));
    rcs = (int *)malloc(maximum_possible_paths * sizeof(int));
    rs = 0;
    top = -1;
    dfs(graph, graphSize, graphColSize, 0);
    *returnSize = rs;
    *returnColumnSizes = rcs;
    return result;
}