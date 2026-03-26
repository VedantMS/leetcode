class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();

        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        queue<pair<int, int>> q;
        q.push({click[0], click[1]});

        board[click[0]][click[1]] = 'B';

        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int count = 0;

            for(int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] == 'M') {
                    count++;
                }
            }

            if(count > 0) {
                board[r][c] = '0' + count;
            }

            else {
                for(int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] == 'E') {
                        q.push({nr, nc});
                        board[nr][nc] = 'B';
                    }
                }
            }
        }

        return board;
    }
};