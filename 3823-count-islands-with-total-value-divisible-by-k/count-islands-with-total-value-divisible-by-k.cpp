class Solution {
public:
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};
    
    long long dfs(vector<vector<int>> &grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        long long val = grid[r][c];

        grid[r][c] = 0;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] != 0) {
                val += dfs(grid, nr, nc);
            }
        }

        return val;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] != 0) {
                    if(dfs(grid, i, j) % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};