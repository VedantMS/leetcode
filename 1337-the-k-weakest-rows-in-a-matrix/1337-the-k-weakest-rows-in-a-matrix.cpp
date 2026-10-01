class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size(), num = k;
        vector<int> a(rows, 0), ans;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols && mat[i][j]; j++) {
                a[i] += mat[i][j];
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < rows; i++) {
            pq.push({a[i], i});
        }

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};