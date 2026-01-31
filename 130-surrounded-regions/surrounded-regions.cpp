class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        board[r][c] = 'A';

        int rows = board.size();
        int cols = board[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] == 'O') {
                dfs(board, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        int i = 0;
        int j;

        while(i < rows) {
            j = 0;
            while(j < cols) {
                if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    if(board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
                j++;
            }
            i++;
        }

        for(i = 1; i < rows - 1; i++) {
            for(j = 1; j < cols - 1; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                if(board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};