class Solution {
public:
    int rows;
    int cols;
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    string str;

    bool dfs(vector<vector<char>>& board, int index, int r, int c) {
        if(index == str.size()) {
            return true;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] == str[index]) {
                if(dfs(board, index + 1, nr, nc))   return true;
            }
        }

        board[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        str = word;

        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, 1, i, j))     return true;
                }
            }
        }

        return false;
    }
};