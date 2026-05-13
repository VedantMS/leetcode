class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> adj(n);

        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2], edge[3]});
        }

        vector<int> time(n, INT_MAX);
        time[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if(t > time[u])     continue;

            for(auto [v, s, e] : adj[u]) {
                if(t > e)       continue;

                int arrivalTime = max(t, s) + 1;

                if(arrivalTime < time[v]) {
                    time[v] = arrivalTime;
                    pq.push({time[v], v});
                }
            }
        }

        return time[n - 1] == INT_MAX ? -1 : time[n - 1];
    }
};