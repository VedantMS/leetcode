class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cnt = edge[2];

            adj[u].push_back({v, cnt + 1});
            adj[v].push_back({u, cnt + 1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) {
                continue;
            }

            for (auto &[v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({d + w, v});
                }
            }
        }

        int ans = 0;

        for (int num : dist) {
            if (num <= maxMoves) {
                ans++;
            }
        }

        for (auto &edge : edges) {
            int src = edge[0];
            int dest = edge[1];
            int w = edge[2];

            int a = dist[src] <= maxMoves ? maxMoves - dist[src] : 0;
            int b = dist[dest] <= maxMoves ? maxMoves - dist[dest] : 0;

            ans += min(w, a + b);
        }

        return ans;
    }
};