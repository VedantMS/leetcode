class Solution {
public:
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    int rows, cols;
    int ans, blocks;

    void path(int row, int col, vector<vector<int>> &grid, int num) {
        int temp = grid[row][col];
        grid[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = dr[i] + row;
            int nc = dc[i] + col;

            if (nr < rows && nr >= 0 && nc < cols && nc >= 0) {
                if (!grid[nr][nc]) {
                    path(nr, nc, grid, num + 1);
                }

                if (grid[nr][nc] == 2 && num == blocks) {
                    ans++;
                }
            }
        }

        grid[row][col] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int r, c;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
                
                if (!grid[i][j]) {
                    blocks++;
                }
            }
        }

        path(r, c, grid, 0);

        return ans;
    }
};