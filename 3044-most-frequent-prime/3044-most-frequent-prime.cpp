class Solution {
public:
    static constexpr int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    static constexpr int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    int rows, cols;
    
    void move(int num, int r, int c, int dir, vector<vector<int>>& mat, unordered_map<int, int> &freq) {
        num = num * 10 + mat[r][c];

        freq[num]++;

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr < rows && nr >= 0 && nc < cols && nc >= 0) {
            move(num, nr, nc, dir, mat, freq);
        }
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();

        int n = 1;

        for (int i = 0; i < max(rows, cols); i++) {
            n *= 10;
        }
        
        unordered_map<int, int> freq;
        vector<bool> prime(n, true);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < 8; k++) {
                    move(0, i, j, k, mat, freq);
                }
            }
        }

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int ans = -1, mx = 0;

        for (auto &[key, val] : freq) {
            if (key > 10 && prime[key]) {
                if (val > mx || (val == mx && key > ans)) {
                    ans = key;
                    mx = val;
                }
            }
        }

        return ans;
    }
};