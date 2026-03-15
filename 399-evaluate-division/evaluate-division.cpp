class Solution {
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> string_to_int;
        unordered_map<int, string> int_to_string;
        vector<double> ans;

        int n = 0;
        for(auto equation : equations) {
            string first = equation[0];
            string second = equation[1];

            if(string_to_int.count(first) == 0) {
                string_to_int[first] = n;
                int_to_string[n] = first;
                n++;
            }

            if(string_to_int.count(second) == 0) {
                string_to_int[second] = n;
                int_to_string[n] = second;
                n++;
            }
        }

        vector<vector<double>> graph(n, vector<double> (n, -1));

        for(int i = 0; i < equations.size(); i++) {
            vector<string> equation = equations[i];
            int first = string_to_int[equation[0]];
            int second = string_to_int[equation[1]];

            graph[first][second] = values[i];
            graph[second][first] = 1 / values[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) graph[i][j]=1;
            }
        }

        for(int vai = 0; vai < n; vai++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(graph[i][j] == -1) {
                        if(graph[i][vai] == -1 || graph[vai][j] == -1)  graph[i][j] = -1;
                        
                        else {
                            graph[i][j] = graph[i][vai] * graph[vai][j];
                            graph[j][i] = 1 / graph[i][j];
                        }
                    }
                }
            }
        }

        for(int i = 0; i < queries.size(); i++) {
            vector<string> query = queries[i];

            if(string_to_int.count(query[0]) == 0 || string_to_int.count(query[1]) == 0)    ans.push_back(-1);
            else    ans.push_back(graph[string_to_int[query[0]]][string_to_int[query[1]]]);
        }

        return ans;
    }
};