class Solution {
public:
    int nodeSum;
    int edgeSum;
    
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
        visited[u] = true;
        nodeSum++;

        for (int &v : adj[u]) {
            edgeSum++;

            if (!visited[v]) {
                dfs(adj, visited, v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                nodeSum = 0;
                edgeSum = 0;

                dfs(adj, visited, i);
                
                if (edgeSum / 2 == (nodeSum * (nodeSum - 1) / 2)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};