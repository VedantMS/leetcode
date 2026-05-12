class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int ans = -1;
        int cities = n;

        for(int i = 0; i < n; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});

            vector<int> dist(n, INT_MAX);
            dist[i] = 0;

            int nodes = 0;
            
            while(!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if(d > dist[u]) {
                    continue;
                }

                for(auto &[v, w] : adj[u]) { 
                    if(dist[u] + w < dist[v] && dist[u] + w <= distanceThreshold)  {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                if(dist[i] <= distanceThreshold) {
                    nodes++;
                }
            }

            if(cities >= nodes) {
                cities = nodes;
                ans = i;
            }
        }

        return ans;
    }
};