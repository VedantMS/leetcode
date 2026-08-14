class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0;
        int r = 0, c = 0;
        vector<bool> row(n, false), col(n, false);

        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if (type == 0) {
                if (!row[index]) {
                    row[index] = true;
                    r++;
                    ans += val * (n - c);
                }
            }
            
            else {
                if (!col[index]) {
                    col[index] = true;
                    c++;
                    ans += val * (n - r);
                }
            }
        }

        return ans;
    }
};