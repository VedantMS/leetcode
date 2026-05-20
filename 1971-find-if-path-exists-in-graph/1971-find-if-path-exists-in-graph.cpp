class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(source);

        vector<bool> visited(n, false);
        visited[source] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(u == destination) {
                return true;
            }

            for(int &v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }
};