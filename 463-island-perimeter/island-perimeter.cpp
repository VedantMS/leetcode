class Solution {
public:
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};
    int perimeter;

    void dfs(vector<vector<int>> &grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        grid[r][c] = 2;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] > 0) {
                if(grid[nr][nc] == 1) {
                    dfs(grid, nr, nc);
                }

                count++;
            }
        }

        perimeter += 4 - count;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        perimeter = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    break;
                }
            }
        }

        return perimeter;
    }
};