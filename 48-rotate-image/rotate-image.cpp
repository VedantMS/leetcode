class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int up = 0;
        int down = n - 1;

        while(up < down) {
            swap(matrix[up], matrix[down]);
            up++;
            down--;
        }

        int cols = 0;

        for(int i = 0; i < n; i++) {
            for(int j = cols; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            cols++;
        }
    }
};