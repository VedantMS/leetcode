class Solution {
public:
    bool diagonals(vector<string> &board, int row, int col) {
        //  Left Diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return true;
            }
        }

        //  Right Diagonal
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return true;
            }
        }

        return false;
    }

    void queens(int row, vector<string> &board, vector<bool> &cols, int &ans) {
        if (row == board.size()) {
            ans++;
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (cols[i] || diagonals(board, row, i)) {
                continue;
            }

            board[row][i] = 'Q';
            cols[i] = true;

            queens(row + 1, board, cols, ans);

            board[row][i] = '.';
            cols[i] = false;
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);

        int ans = 0;

        queens(0, board, cols, ans);

        return ans;
    }
};