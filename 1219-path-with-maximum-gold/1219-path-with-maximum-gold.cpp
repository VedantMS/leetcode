class Solution {
public:
    int rows, cols;
    int ans;

    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    void gold(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c, int sum) {
        visited[r][c] = true;

        sum += grid[r][c];

        ans = max(ans, sum);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] > 0 && !visited[nr][nc]) {
                gold(grid, visited, nr, nc, sum);
            }
        }

        visited[r][c] = false;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    ans = 0;
                    break;
                }
                
                ans += grid[i][j];
            }
        }

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    gold(grid, visited, i, j, 0);
                }
            }
        }

        return ans;
    }
};