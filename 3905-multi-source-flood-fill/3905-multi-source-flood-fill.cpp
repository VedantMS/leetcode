class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int> (m, 0));
        queue<vector<int>> q;

        for (auto &source : sources) {
            ans[source[0]][source[1]] = source[2];
            q.push({source[0], source[1], source[2]});
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int level = q.size();
            map<pair<int, int>, int> mp;

            for (int i = 0; i < level; i++) {
                auto source = q.front();
                q.pop();
                
                int r = source[0];
                int c = source[1];
                int color = source[2];

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < n && nr >= 0 && nc < m && nc >= 0 && ans[nr][nc] == 0) {
                        mp[{nr, nc}] = max(mp[{nr, nc}], color);
                    }
                }
            }

            for (auto &[pos, color] : mp) {
                ans[pos.first][pos.second] = color;
                q.push({pos.first, pos.second, color});
            }
        }

        return ans;
    }
};