class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        k %= n * m;

        if (k == 0) {
            return grid;
        }

        while (k--) {
            int num = grid[n - 1][m - 1];

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i || j) {
                        grid[i][j] = j ? grid[i][j - 1] : grid[i - 1][m - 1];
                    }
                }
            }

            grid[0][0] = num;
        }

        return grid;
    }
};