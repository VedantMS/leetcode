class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        for (auto &prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<bool> ans;

        for (auto &query : queries) {
            int a = query[0], b = query[1];
            queue<int> q;
            vector<bool> visited(numCourses, false);

            q.push(a);
            visited[a] = true;
            ans.push_back(false);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                bool flag = false;

                for (int &v : adj[u]) {
                    if (v == b) {
                        ans.back() = true;
                        flag = true;
                        break;
                    }
                    
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }

                if (flag) {
                    break;
                }
            }
        }

        return ans;
    }
};