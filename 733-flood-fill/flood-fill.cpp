class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int col = image[sr][sc];

        if(col == color)    return image;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            image[r][c] = color;

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < rows && nr >= 0  && nc < cols && nc >= 0 && image[nr][nc] == col) {
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};