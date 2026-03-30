class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = -1;

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int level = q.size();
            
            for(int i = 0; i < level; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }

            ans++;
        }

        if(ans == 0) {
            return -1;
        }

        return ans;
    }
};