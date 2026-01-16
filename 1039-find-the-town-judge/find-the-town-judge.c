int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int indegree[n + 1];
    int outdegree[n + 1];
    
    for(int i = 0; i <= n; i++) {
        outdegree[i] = 0;
        indegree[i] = 0;
    }
    for(int i = 0; i < trustSize; i++) {
        outdegree[trust[i][0]] = 1;
        indegree[trust[i][1]]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!outdegree[i] && indegree[i] == n - 1) {
            return i;
        }
    }
    return -1;
}