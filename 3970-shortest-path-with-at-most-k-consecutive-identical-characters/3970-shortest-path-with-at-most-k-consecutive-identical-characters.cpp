class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> dist(n, vector<int> (k + 1, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int ,int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d != dist[u][count]) {
                continue;
            }

            if (u == n - 1) {
                return d;
            }

            for (auto [v, w] : adj[u]) {
                int ct = labels[u] == labels[v] ? count + 1 : 1;

                if (ct > k) {
                    continue;
                }

                if (d + w < dist[v][ct]) {
                    dist[v][ct] = d + w;
                    pq.push({d + w, v, ct});
                }
            }
        }

        return -1;
    }
};