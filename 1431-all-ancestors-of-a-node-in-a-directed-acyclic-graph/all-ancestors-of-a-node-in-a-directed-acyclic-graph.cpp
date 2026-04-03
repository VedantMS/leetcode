class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            visited[i] = true;

            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = true;
                        
                        ans[v].push_back(i);
                        q.push(v);
                    }
                }
            }
        }
        
        return ans;
    }
};