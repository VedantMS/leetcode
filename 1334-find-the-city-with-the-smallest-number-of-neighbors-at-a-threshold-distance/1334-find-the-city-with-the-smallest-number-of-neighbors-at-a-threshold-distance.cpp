class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int> (n, 1e9));

        for(auto &edge : edges) {
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }

        for(int i = 0; i < n; i++)      adj[i][i] = 0;

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int ans = -1;
        int cities = n;

        for(int i = 0; i < n; i++) {
            int count = -1;

            for(int j = 0; j < n; j++) {
                if(adj[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if(count <= cities) {
                ans = i;
                cities = count;
            }
        }

        return ans;
    }
};