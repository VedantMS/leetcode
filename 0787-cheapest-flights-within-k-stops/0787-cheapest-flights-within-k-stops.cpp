class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        int ans = 0;
        
        while(!q.empty() && ans <= k) {
            int num = q.size();

            for(int i = 0; i < num; i++) {
                auto [u, w] = q.front();
                q.pop();

                for(auto [v, val] : adj[u]) {
                    if(w + val < dist[v]) {
                        dist[v] = w + val;
                        q.push({v, w + val});
                    }
                }
            }

            ans++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};