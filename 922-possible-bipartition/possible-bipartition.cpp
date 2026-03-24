class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for(auto edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;

        vector<int> color(n + 1, 0);
        
        for(int i = 1; i < n + 1; i++) {
            if(color[i] == 0) {
                color[i] = 1;
                q.push(i);

                while(!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for(int v : adj[u]) {
                        if(color[v] == 0) {
                            color[v] = color[u] * -1;
                            q.push(v);
                        }

                        else if(color[u] == color[v]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};