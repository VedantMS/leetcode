class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int vertex) {
        if(color[vertex] == 1)  return false;       //  Cycle
        if(color[vertex] == 2)  return true;        //  Safe
        if(color[vertex] == 3)  return false;       //  Unsafe

        color[vertex] = 1;

        int n = graph[vertex].size();
        for(int i = 0; i < n; i++) {
            if(!dfs(graph, color, graph[vertex][i])) {
                color[vertex] = 3;
                return false;
            }
        }

        color[vertex] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        //  0: Unvisited
        //  1: Currently Being Visited
        //  2: Safe
        //  3. Unsafe

        vector<int> answer;
        for(int i = 0; i < n; i++) {
            if(dfs(graph, color, i)) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};