class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m, vector<int> (n, 0));

        for (auto indice : indices) {
            for (int i = 0; i < n; i++) {
                mat[indice[0]][i]++;
            }

            for (int i = 0; i < m; i++) {
                mat[i][indice[1]]++;
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] % 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};