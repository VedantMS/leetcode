class Solution {
public:
    int rows;
    int cols;
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int r, int c) {
        if(memo[r][c] != 0) {
            return memo[r][c];
        }
        
        int maxlen = 1;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && matrix[nr][nc] > matrix[r][c]) {
                maxlen = max(maxlen, 1 + dfs(matrix, memo, nr, nc));
            }
        }
        
        return memo[r][c] = maxlen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        
        rows = matrix.size();
        cols = matrix[0].size();

        vector<vector<int>> memo(rows, vector<int> (cols, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int len = dfs(matrix, memo, i, j);
                if(ans < len) {
                    ans = len;
                }
            }
        }

        return ans;
    }
};