class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        int num = 1;
        vector<int> depth(n);

        for (int i = 0; i < n; i++) {
            if (depth[i]) {
                continue;
            }

            int start = num;
            int u = i;

            while (u != -1 && !depth[u]) {
                depth[u] = num++;
                u = edges[u];
            }

            if (u != -1 && depth[u] >= start) {
                ans = max(ans, num - depth[u]);
            }
        }

        return ans;
    }
};