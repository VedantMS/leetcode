class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        int total = 0;
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
                total++;
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                    ans.push_back(v);
                    total++;
                }
            }
        }

        return total == numCourses ? ans : vector<int>();
    }
};