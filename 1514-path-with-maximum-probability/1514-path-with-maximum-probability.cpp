class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        int index = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            double p = succProb[index++];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0);
        prob[start_node] = 1;

        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});

        while (!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();

            if (p > prob[u]) {
                continue;
            }

            for (auto &[v, w] : adj[u]) {
                if (p * w > prob[v]) {
                    prob[v] = p * w;
                    pq.push({p * w, v});
                }
            }
        }

        return prob[end_node];
    }
};