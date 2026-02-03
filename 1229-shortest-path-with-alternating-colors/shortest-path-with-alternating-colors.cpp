class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> answer(n, -1);

        for(int i = 0; i < redEdges.size(); i++) {
            adj[redEdges[i][0]].push_back({redEdges[i][1], 0});

        }
        for(int i = 0; i < blueEdges.size(); i++) {
            adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
        }

        vector<vector<bool>> visited(n, vector<bool>(2, false));

        queue<pair<int, int>> q;
        q.push({0, -1});

        visited[0][0] = true;
        visited[0][1] = true;
        answer[0] = 0;

        int count = 0;

        while(!q.empty()) {
            int level = q.size();
            count++;

            for(int i = 0; i < level; i++) {
                int u = q.front().first;
                int previousColor = q.front().second;
                q.pop();

                for(int j = 0; j < adj[u].size(); j++) {
                    int v = adj[u][j].first;
                    int edgeColor = adj[u][j].second;

                    if(edgeColor != previousColor && !visited[v][edgeColor]) {
                        visited[v][edgeColor] = true;
                        q.push({v, edgeColor});
                    

                        if(answer[v] == -1) {
                            answer[v] = count;
                        }
                    }
                }
            }
        }
        return answer;
    }
};