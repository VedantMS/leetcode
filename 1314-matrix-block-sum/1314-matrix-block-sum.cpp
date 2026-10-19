class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size();
        
        for (int i = 1; i < cols; i++) {
            mat[0][i] += mat[0][i - 1];
        }

        for (int i = 1; i < rows; i++) {
            mat[i][0] += mat[i - 1][0];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(rows, vector<int> (cols, 0));

        for (int i = 0; i < rows; i++) {
            int r1 = max(0, i - k), r2 = min(rows - 1, i + k);

            for (int j = 0; j < cols; j++) {
                int c1 = max(0, j - k), c2 = min(cols - 1, j + k);
                
                ans[i][j] = mat[r2][c2];

                if (r1 > 0) {
                    ans[i][j] -= mat[r1 - 1][c2];
                }

                if (c1 > 0) {
                    ans[i][j] -= mat[r2][c1 - 1];
                }

                if (r1 > 0 && c1 > 0) {
                    ans[i][j] += mat[r1 - 1][c1 - 1];
                }
            }
        }

        return ans;
    }
};