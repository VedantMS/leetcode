class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        if (rows * cols != r * c) {
            return mat;
        }
        
        vector<vector<int>> ans(r, vector<int> (c));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int index = i * cols + j;
                
                ans[index / c][index % c] = mat[i][j];
            }
        }

        return ans;
    }
};