void dfs(int** isConnected, int isConnectedSize, int *visited, int vertex) {
    visited[vertex] = 1;
    for(int i = 0; i < isConnectedSize; i++) {
        if(isConnected[vertex][i] && !visited[i]) {
            dfs(isConnected, isConnectedSize, visited, i);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int provinces = 0;
    int *visited = (int *)calloc(isConnectedSize, sizeof(int));
    for(int i = 0; i < isConnectedSize; i++) {
        if(!visited[i]) {
            provinces++;
            dfs(isConnected, isConnectedSize, visited, i);
        }
    }
    return provinces;
}