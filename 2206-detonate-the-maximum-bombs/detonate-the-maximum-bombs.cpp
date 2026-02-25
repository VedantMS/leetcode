class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool> &visited, int node) {
        visited[node] = true;
        int num = 1;
        for(int i : adj[node]) {
            if(!visited[i]) {
                num += dfs(adj, visited, i);
            }
        }
        
        return num;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r = bombs[i][2];

            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                if(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int num = dfs(adj, visited, i);
            
            if(num == n) {
                return n;
            }

            if(ans < num) {
                ans = num;
            }
        }

        return ans;
    }
};