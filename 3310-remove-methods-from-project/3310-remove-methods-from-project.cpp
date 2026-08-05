class Solution {
public:
    void suspiction(int u, vector<vector<int>> &adj, vector<bool> &suspicious) {
        suspicious[u] = true;

        for (int v : adj[u]) {
            if (!suspicious[v]) {
                suspiction(v, adj, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);

        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        suspiction(k, adj, suspicious);

        for (auto &edge : invocations) {
            if (!suspicious[edge[0]] && suspicious[edge[1]]) {
                vector<int> ans(n);

                for (int i = 0; i < n; i++) {
                    ans[i] = i;
                }

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};