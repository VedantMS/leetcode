void dfs(char **board, int rows, int cols, int r, int c) {
    board[r][c] = '.';

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] == 'X')
            dfs(board, rows, cols, nr, nc);
    }
}

int countBattleships(char** board, int boardSize, int* boardColSize) {
    int rows = boardSize;
    int cols = *boardColSize;
    int ans = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(board[i][j] == 'X') {
                dfs(board, rows, cols, i, j);
                ans++;
            }
        }
    }

    return ans;
}