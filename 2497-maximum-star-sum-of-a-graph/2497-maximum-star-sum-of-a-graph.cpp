class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(vals.size());

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(vals[v]);
            adj[v].push_back(vals[u]);
        }

        int ans = INT_MIN;

        for (int i = 0; i < vals.size(); i++) {
            priority_queue<int> pq;

            for (int &num : adj[i]) {
                pq.push(num);
            }

            int sum = vals[i], j = 0;

            while (!pq.empty() && j < k) {
                if (pq.top() < 0) {
                    break;
                }

                sum += pq.top();
                pq.pop();

                j++;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};