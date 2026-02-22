class Solution {
public:
    int maxFish;
    int tempFish;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        tempFish += grid[r][c];

        grid[r][c] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] > 0) {
                dfs(grid, nr, nc);
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        maxFish = 0;
        tempFish = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] > 0) {
                    tempFish = 0;
                    dfs(grid, i, j);
                    if(maxFish < tempFish) {
                        maxFish = tempFish;
                    }
                }
            }
        }

        return maxFish;
    }
};