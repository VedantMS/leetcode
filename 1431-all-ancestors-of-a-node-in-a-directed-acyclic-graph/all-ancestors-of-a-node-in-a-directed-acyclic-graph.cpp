class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<set<int>> temp(n);
        vector<int> indegree(n, 0);
        vector<bool> visited(n, false);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        while(1) {
            bool push = false;
            for(int i = 0; i < n; i++) {
                if(indegree[i] == 0 && !visited[i]) {
                    q.push(i);
                    push = true;
                }
            }

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                visited[u] = true;

                for(int v : adj[u]) {
                    temp[v].insert(u);
                    indegree[v]--;

                    for(int a : temp[u]) {
                        temp[v].insert(a);
                    }
                }
            }

            if(!push)   break;
        }

        vector<vector<int>> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i].assign(temp[i].begin(), temp[i].end());
        }

        return ans;
    }
};