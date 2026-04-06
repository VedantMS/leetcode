class Solution {
public:
    int components;
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
        visited[u] = true;

        for(int v : adj[u]) {
            if(!visited[v])     dfs(adj, visited, v);
        } 
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        int edges = connections.size();
        
        components = 0;
        
        if(edges < n - 1)   return -1;

        for(auto connection : connections) {
            int u = connection[0];
            int v = connection[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                components++;
            }
        }

        return components - 1;
    }
};