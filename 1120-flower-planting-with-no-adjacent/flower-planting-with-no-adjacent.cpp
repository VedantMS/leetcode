class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        vector<int> ans(n, 0);

        for(auto &path : paths) {
            int u = path[0];
            int v = path[1];

            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        for(int u = 0; u < n; u++) {
            vector<bool> used(5, false);

            for(int v : adj[u]) {
                used[ans[v]] = true;
            }

            for(int clr = 1; clr <= 4; clr++) {
                if(!used[clr]) {
                    ans[u] = clr;
                    break;
                }
            }
        }
        
        return ans;
    }
};