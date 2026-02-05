class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adjacencyMatrix(n, vector<bool> (n, false));
        vector<int> degree(n, 0);
        for(auto &edge : roads) {
            int u = edge[0];
            int v = edge[1];

            adjacencyMatrix[u][v] = true;
            adjacencyMatrix[v][u] = true;
            
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        int answer = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j] - (adjacencyMatrix[i][j] ? 1 : 0);
                answer = max(rank, answer);
            }
        }

        return answer;
    }
};