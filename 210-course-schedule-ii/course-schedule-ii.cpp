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

        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                ans.push_back(i);
            }
        }

        int head = 0;
        while(head < ans.size()) {
            int u = ans[head];
            head++;

            for(int v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    ans.push_back(v);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};