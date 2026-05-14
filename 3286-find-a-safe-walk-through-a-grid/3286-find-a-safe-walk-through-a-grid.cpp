class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;

        if(grid[0][0] == 1)     pq.push({health - 1, 0, 0});
        else                    pq.push({health, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [h, r, c] = pq.top();

            if(h >= 1 && r == rows - 1 && c == cols - 1)      return true;

            pq.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && grid[nr][nc] != -1) {
                    if(grid[nr][nc] == 0)       pq.push({h, nr, nc});

                    else                        pq.push({h - 1, nr, nc});

                    grid[nr][nc] = -1;
                }
            }
        }

        return false;
    }
};