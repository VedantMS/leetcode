class Solution {
public:
    int rows, cols;

    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    int dfs(int r, int c, int color, vector<vector<int>> &grid) {
        grid[r][c] = color;
        int sum = 0;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] == 1) {
                sum += dfs(nr, nc, color, grid);
            }
        }

        return sum + 1;
    }

    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int color = 1;
        vector<int> area(2, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, ++color, grid);
                    area.push_back(size);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!grid[i][j]) {
                    int num = 1;
                    
                    int a = i > 0 ? grid[i - 1][j] : 0;
                    int b = i < rows - 1 ? grid[i + 1][j] : 0;
                    int c = j > 0 ? grid[i][j - 1] : 0;
                    int d = j < cols - 1 ? grid[i][j + 1] : 0;

                    num += area[a];
                    num += a != b ? area[b] : 0;
                    num += a != c && b != c ? area[c] : 0;
                    num += a != d && b != d && c != d ? area[d] : 0;

                    ans = max(ans, num);
                }
            }
        }

        return ans == 0 ? rows * cols : ans;
    }
};