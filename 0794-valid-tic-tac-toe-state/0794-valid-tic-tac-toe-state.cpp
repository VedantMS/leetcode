class Solution {
public:
    bool winner(vector<string> &board, char symbol) {
        for (int i = 0; i < 3; i++) {
            if (board[i] == string(3, symbol) ||
                (board[0][i] == symbol &&  board[1][i] == symbol && board[2][i] == symbol)) {
                return true;
            }
        }

        if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
            (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
            return true;
        }

        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;

        for (auto &row : board) {
            for (auto &ch : row) {
                if (ch == 'X') {
                    x++;
                }

                else if (ch == 'O') {
                    o++;
                }
            }
        }

        if (x < o || abs(x - o) > 1) {
            return false;
        }

        bool a = winner(board, 'X');
        bool b = winner(board, 'O');

        if ((a && b) || (a && (x != o + 1)) || (b && (x != o))) {
            return false;
        }

        return true;
    }
};