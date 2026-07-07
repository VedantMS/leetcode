class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;

            for (int j = 0; j < n; j++) {
                x = max(x, grid[i][j]);
                y = max(y, grid[j][i]);
                
                if (grid[i][j] > 0) {
                    ans++;
                }
            }

            ans += x + y;
        }

        return ans;
    }
};