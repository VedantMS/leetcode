bool dfs(int **graph, int graphSize, int *graphColSize, int *color, int c, int vertex) {
    color[vertex] = c;
    for(int i = 0; i < graphColSize[vertex]; i++) {
        int neighbor = graph[vertex][i];
        if(!color[neighbor]) {
            if(!dfs(graph, graphSize, graphColSize, color, -c, neighbor)) {
                return 0;
            }
        }
        if(color[vertex] == color[neighbor]) {
            return 0;
        }
    }
    return 1;
}
bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];
    for(int i = 0; i < graphSize; i++) {
        color[i] = 0;
    }
    bool ans = dfs(graph, graphSize, graphColSize, color, 1, 0);
    for(int i = 0; i < graphSize; i++) {
        if(!color[i]) {
            ans = ans && dfs(graph, graphSize, graphColSize, color, 1, i);
        }
    }
    return ans;
}