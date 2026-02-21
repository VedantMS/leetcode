class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        long long ans = 0;
        long long remainingNodes = n;
        
        for(int u = 0; u < n; u++) {
            if(!visited[u]) {
                queue<int> q;
                q.push(u);
                
                visited[u] = true;

                long long compCount = 0;
                while(!q.empty()) {
                    int v = q.front();
                    q.pop();
                    compCount++;
                    for(int i : adj[v]) {
                        if(!visited[i]) {
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }

                remainingNodes -= compCount;
                ans += compCount * remainingNodes;
            }
        }

        return ans;
    }
};