class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u) {
        visited[u] = true;

        int n = graph[u].size();

        for(int v : graph[u]) {
            if(!visited[v]) {
                dfs(graph, visited, v);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ans = 0;

        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ans++;
                dfs(graph, visited, i);
            }
        }

        return n - ans;
    }
};