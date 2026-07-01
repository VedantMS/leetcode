class Solution {
public:
    int rows, cols;
    int ans = 0;

    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    void check(vector<vector<int>> &grid) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    ans = 0;
                    return;
                }

                ans += grid[i][j];
            }
        }
    }

    void gold(vector<vector<int>> &grid, int r, int c, int sum) {
        int num = grid[r][c];
        grid[r][c] = 0;

        sum += num;

        ans = max(ans, sum);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] > 0) {
                gold(grid, nr, nc, sum);
            }
        }

        grid[r][c] = num;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        check(grid);

        if (ans != 0) {
            return ans;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    gold(grid, i, j, 0);
                }
            }
        }

        return ans;
    }
};