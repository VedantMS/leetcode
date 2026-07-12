class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int> (8, 0));
        
        for (auto &queen : queens) {
            board[queen[0]][queen[1]] = 1;
        }

        int xKing = king[0];
        int yKing = king[1];

        vector<vector<int>> ans;
        
        vector<int> dir = {-1, 0, 1};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 1; k < 8; k++) {
                    int nr = xKing + dir[i] * k;
                    int nc = yKing + dir[j] * k;

                    if (nr < 8 && nr >= 0 && nc < 8 && nc >= 0 && board[nr][nc]) {
                        ans.push_back({nr, nc});
                        break;
                    }
                }
            }
        }

        return ans;
    }
};