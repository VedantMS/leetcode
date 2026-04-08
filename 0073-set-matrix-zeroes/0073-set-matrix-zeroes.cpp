class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> row(rows, false);
        vector<bool> col(cols, false);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    if(!row[i]) {
                        row[i] = true;
                    }

                    if(!col[j]) {
                        col[j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            if(row[i]) {
                for(int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < cols; i++) {
            if(col[i]) {
                for(int j = 0; j < rows; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};