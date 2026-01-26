class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        int steps = 0;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                pair<int, int> current = q.front();
                q.pop();

                int r = current.first;
                int c = current.second;

                for(int j = 0; j < 4; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && maze[nr][nc] == '.') {
                        if(nr == 0 || nc == 0 || nr == rows - 1 || nc == cols - 1) {
                            return steps + 1;
                        }
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};