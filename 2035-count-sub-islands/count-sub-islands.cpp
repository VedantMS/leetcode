class Solution {
public:
    bool flag;

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if(grid1[r][c] != 1)    flag = false;
        
        grid2[r][c] = 0;

        int rows = grid2.size();
        int cols = grid2[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid2[nr][nc] == 1)      dfs(grid1, grid2, nr, nc);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();

        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid2[i][j] == 1) {
                    flag = true;
                    dfs(grid1, grid2, i, j);
                    if(flag)   ans++;
                }
            }
        }

        return ans;
    }
};