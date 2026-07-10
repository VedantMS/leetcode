class Solution {
public:
    bool row[9][10];
    bool col[9][10];
    bool box[9][10];

    bool sudoku(vector<vector<char>> &board, vector<pair<int, int>> &block, int index) {
        if (index == block.size()) {
            return true;
        }

        int r = block[index].first;
        int c = block[index].second;

        for (int i = 1; i <= 9; i++) {
            int j = (r / 3) * 3 + (c / 3);
            
            if (row[r][i] || col[c][i] || box[j][i]) {
                continue;
            }

            board[r][c] = i + '0';
            
            row[r][i] = col[c][i] = box[j][i] = true;

            if (sudoku(board, block, index + 1)) {
                return true;
            }

            row[r][i] = col[c][i] = box[j][i] = false;
        }

        board[r][c] = '.';

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> block;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    block.push_back({i, j});
                    continue;
                }

                int num = board[i][j] - '0';

                row[i][num] = col[j][num] = box[(i / 3) * 3 + (j / 3)][num] = true;
            }
        }

        sudoku(board, block, 0);
    }
};