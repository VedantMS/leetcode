class Solution {
public:
    void island(vector<vector<int>>& grid, queue<pair<int, int>> &q, int r, int c) {
        int n = grid.size();
        grid[r][c] = 2;
        q.push({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 1) {
                island(grid, q, nr, nc);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int flips = 0;
    
        queue<pair<int, int>> q;
        
        bool flag = false;
        for(int i = 0; i < n && !flag; i++) {
            for(int j = 0; j < n && !flag; j++) {
                if(grid[i][j] == 1) {
                    island(grid, q, i, j);
                    flag = true;
                }
            }
        }

        while(!q.empty()) {
            int level = q.size();
            for(int i = 0; i < level; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for(int j = 0; j < 4; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] != 2) {
                        if(grid[nr][nc] == 1) {
                            return flips;
                        }
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            flips++;
        }
        return flips;
    }
};