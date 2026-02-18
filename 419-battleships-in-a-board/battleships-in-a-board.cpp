class Solution {
public:

    void dfs(vector<vector<char>> &board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        board[r][c] = '.';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] == 'X')
                dfs(board, nr, nc);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int ans = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'X') {
                    dfs(board, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};