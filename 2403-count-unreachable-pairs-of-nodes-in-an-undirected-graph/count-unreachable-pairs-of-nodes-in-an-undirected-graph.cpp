class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
        visited[u] = true;

        int compCount = 1;
        for(int v : adj[u]) {
            if(!visited[v]) {
                compCount += dfs(adj, visited, v);
            }
        }

        return compCount;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        long long ans = 0;
        long long remainingNodes = n;
        
        for(int u = 0; u < n; u++) {
            if(!visited[u]) {
                long long compCount = dfs(adj, visited, u);

                remainingNodes -= compCount;
                ans += compCount * remainingNodes;
            }
        }

        return ans;
    }
};