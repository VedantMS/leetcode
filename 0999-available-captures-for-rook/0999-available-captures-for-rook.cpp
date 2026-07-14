class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;

                    break; 
                }
            }
        }
        
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int ans = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 8; j++) {
                int nr = r + j * dir[i][0];
                int nc = c + j * dir[i][1];

                if (nr < 8 && nr >= 0 && nc < 8 && nc >= 0) {
                    if (board[nr][nc] != '.') {
                        ans += board[nr][nc] == 'p' ? 1 : 0;
                        
                        break;
                    }
                }

                else {
                    break;
                }
            }
        }

        return ans;
    }
};