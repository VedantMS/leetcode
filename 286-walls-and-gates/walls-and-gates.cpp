class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {        
            auto [r, c] = q.front();
            q.pop();

            for(int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
            
        }
    }
};
