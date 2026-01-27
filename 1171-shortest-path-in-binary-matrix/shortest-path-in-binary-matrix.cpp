class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        
        int steps = 1;
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if(n == 1) {
            return 1;
        }
        
        q.push({0, 0});
        grid[0][0] = 1;
        
        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j = 0; j < 8; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] != 1) {
                        if(nr == n - 1 && nc == n - 1) {
                            return steps + 1;
                        }
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};