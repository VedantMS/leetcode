void dfs(int **rooms, int *visited, int *roomsColSize, int vertex) {
    visited[vertex] = 1;
    for(int i = 0; i < roomsColSize[vertex]; i++) {
        if(!visited[rooms[vertex][i]]) {
            dfs(rooms, visited, roomsColSize, rooms[vertex][i]);
        }
    }
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];
    for(int i = 0; i < roomsSize; i++) {
        visited[i] = 0;
    }
    dfs(rooms, visited, roomsColSize, 0);
    for(int i = 0; i < roomsSize;  i++) {
        if(!visited[i]) {
            return 0;
        }
    }
    return 1;
}