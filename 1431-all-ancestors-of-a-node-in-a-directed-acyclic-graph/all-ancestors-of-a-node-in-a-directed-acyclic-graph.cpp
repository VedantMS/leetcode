class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        vector<int> indegree(n, 0);
        vector<bool> visited(n, false);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);

            queue<int> q;
            q.push(i);

            visited[i] = true;

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