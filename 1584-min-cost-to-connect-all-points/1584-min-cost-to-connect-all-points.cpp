class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int ans = 0;
        
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        //  dist, vertex
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;
            ans += dist;

            for (auto &[v, d] : adj[u]) {
                if (!visited[v]) {
                    pq.push({d, v});
                }
            }
        }

        return ans;
    }
};