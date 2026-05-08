class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int ans = 0;
        
        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;

        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int cell = q.front();
            q.pop();

            if(cell == n * n) {
                return dist[cell];
            }
            
            for(int i = cell + 1; i <= cell + 6 && i <= n * n; i++) {
                int row = (i - 1) / n;
                int col = (i - 1) % n;

                int r = (n - 1) - row;
                int c = row % 2 == 0 ? col : n - 1 - col;
                
                int next = board[r][c] == -1 ? i : board[r][c];

                if(dist[next] == -1) {
                    dist[next] = dist[cell] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};