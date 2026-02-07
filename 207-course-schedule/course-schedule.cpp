class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int edges = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(auto &edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<bool> visited(numCourses, false);
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                indegree[v]--;
            }
            for(int i = 0; i < numCourses; i++) {
                if(indegree[i] == 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for(bool ans : visited) {
            if(!ans) {
                return false;
            }
        }

        return true;
    }
};