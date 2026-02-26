class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                
                int sum = 0;
                for(int k = 0; k < 8; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] != 0) {
                        if(board[nr][nc] == 1 || board[nr][nc] == -1) { 
                            sum++;
                        }
                    }
                }

                if(board[i][j] == 0 && sum == 3) {
                    board[i][j] = 2;
                }

                else if(board[i][j] == 1 && (sum < 2 || sum > 3)) {
                    board[i][j] = -1;
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == -1) {
                    board[i][j] = 0;
                }

                else if(board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};