/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int *indegree = (int *)calloc(n, sizeof(int));
    int count = n;
    for(int i = 0; i < edgesSize; i++) {
        if(indegree[edges[i][1]] == 0) {
            count--;
        }
        indegree[edges[i][1]]++;
    }

    int *answer = (int *)malloc(count * sizeof(int));
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            answer[index++] = i;
        }
    }

    *returnSize = count;
    return answer;
}