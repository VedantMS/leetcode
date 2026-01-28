class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, -1));

        if(rows == 1 && cols == 1) {
            result[0][0] = 0;
            return result;
        }

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && result[nr][nc] == -1) {
                        result[nr][nc] = result[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return result;
    }
};