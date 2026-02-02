class Solution {
public:
    
    int count;
    
    void dfs(vector<vector<pair<int, bool>>> &adj, vector<bool> &visited, int node) {
        visited[node] = true;

        int n = adj[node].size();
        for(int i = 0; i < n; i++) {
            int v = adj[node][i].first;
            bool is_original = adj[node][i].second;
            
            if(!visited[v]) {
                if(is_original) {
                    count++;
                }
            
                dfs(adj, visited, v);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj(n);
        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back({connections[i][1], true});
            adj[connections[i][1]].push_back({connections[i][0], false});
        }
        
        vector<bool> visited(n, false);

        count = 0;

        dfs(adj, visited, 0);

        return count;
    }
};