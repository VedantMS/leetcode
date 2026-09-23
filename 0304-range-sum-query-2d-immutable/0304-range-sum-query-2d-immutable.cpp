class NumMatrix {
public:
    vector<vector<int>> mat;
    int rows, cols;

    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        
        for (int i = 1; i < cols; i++) {
            matrix[0][i] += matrix[0][i - 1];
        }

        for (int i = 1; i < rows; i++) {
            matrix[i][0] += matrix[i - 1][0];
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }

        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        bool row = row1 - 1 >= 0, col = col1 - 1 >= 0;

        return mat[row2][col2] - (col ? mat[row2][col1 - 1] : 0) - (row ? mat[row1 - 1][col2] : 0) + (row && col ? mat[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */