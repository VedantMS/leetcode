class Solution {
public:
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    vector<vector<bool>> visited;

    int rows;
    int cols;

    bool ans;

    void dfs(vector<vector<char>> &grid, int r, int c, int prev_r, int prev_c) {
        visited[r][c] = true;
        
        for(int i = 0; i < 4; i++) {   
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] == grid[r][c]) {
                if(nr != prev_r || nc != prev_c) {
                    if(visited[nr][nc])     ans = true;
                    
                    else    dfs(grid, nr, nc, r, c);
                }
            }
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        ans = false;

        rows = grid.size();
        cols = grid[0].size();

        visited.assign(rows, vector<bool> (cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!visited[i][j]) {
                    dfs(grid, i, j, i, j);
                }

                if(ans)     return true;
            }
        }

        return false;
    }
};