class Solution {
public:
    vector<int> disc;
    vector<int> low;
    
    int timer = 1;

    void dfs(vector<vector<int>> &adj, vector<vector<int>> &ans, int node, int u) {
        disc[u] = low[u] = timer++;

        for(int v : adj[u]) {
            if(v == node) {
                continue;
            }

            if(!disc[v]) {
                dfs(adj, ans, u, v);
                
                low[u] = min(low[u], low[v]);

                if(low[v] > disc[u]) {
                    ans.push_back({u, v});
                }
            }

            else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto &connection : connections) {
            int u = connection[0];
            int v = connection[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        disc.assign(n, 0);
        low.assign(n, 0);

        vector<vector<int>> ans;

        dfs(adj, ans, 0, 0);

        return ans;
    }
};