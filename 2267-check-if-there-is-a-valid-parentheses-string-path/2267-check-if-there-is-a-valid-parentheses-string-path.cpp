class Solution {
public:
    int rows, cols;

    bool dfs(int r, int c, int num, vector<vector<char>>& grid, vector<vector<vector<int>>> &dp) {
        num += grid[r][c] == '(' ? 1 : -1;

        if (r == rows - 1 && c == cols - 1) {
            return num == 0;
        }

        if (num < 0) {
            return false;
        }

        if (dp[r][c][num] != -1) {
            return dp[r][c][num];
        }

        dp[r][c][num] = r + 1 < rows && dfs(r + 1, c, num, grid, dp) || c + 1 < cols && dfs(r, c + 1, num, grid, dp);

        return dp[r][c][num];
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        if (grid[0][0] == ')' || grid[rows - 1][cols - 1] == '(' || (rows + cols - 1) % 2) {
            return false;
        }

        vector<vector<vector<int>>> dp(rows, vector<vector<int>> (cols, vector<int> (101, -1)));

        return dfs(0, 0, 0, grid, dp);
    }
};