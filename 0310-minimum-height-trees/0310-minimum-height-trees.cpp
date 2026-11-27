class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            deg[edge[0]]++;
            deg[edge[1]]++;
        }

        queue<int> leaves;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                leaves.push(i);
            }
        }

        int num = n;

        while (num > 2) {
            int count = leaves.size();
            num -= count;

            for (int i = 0; i < count; i++) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbour : adj[leaf]) {
                    if (--deg[neighbour] == 1) {
                        leaves.push(neighbour);
                    }
                }
            }
        }

        vector<int> ans;

        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }

        return ans;
    }
};