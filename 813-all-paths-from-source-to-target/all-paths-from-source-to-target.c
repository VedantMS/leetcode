/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXN 15

int** result;
int* returnColumnSizes;
int returnSize;
int path[MAXN];
int pathSize;

void dfs(int** graph, int graphSize, int* graphColSize, int node) {
    path[pathSize++] = node;

    if (node == graphSize - 1) {
        result[returnSize] = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++)
            result[returnSize][i] = path[i];
        returnColumnSizes[returnSize++] = pathSize;
    } else {
        for (int i = 0; i < graphColSize[node]; i++) {
            dfs(graph, graphSize, graphColSize, graph[node][i]);
        }
    }
    pathSize--;
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize,
                           int* returnSizeOut, int** returnColumnSizesOut) {

    result = (int**)malloc(10000 * sizeof(int*));
    returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    returnSize = 0;
    pathSize = 0;

    dfs(graph, graphSize, graphColSize, 0);

    *returnSizeOut = returnSize;
    *returnColumnSizesOut = returnColumnSizes;
    return result;
}