class Solution {
public:
    static constexpr int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    static constexpr int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    int rows, cols;

    bool isPrime(int num) {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }
    
    void move(int r, int c, int dir, vector<vector<int>>& mat, unordered_map<int, int> &freq) {
        int nr = r, nc = c;
        int num = 0;
        
        while (nr < rows && nr >= 0 && nc < cols && nc >= 0) {
            num = num * 10 + mat[nr][nc];
            
            if (num > 10 && (freq.contains(num) || isPrime(num))) {
                freq[num]++;
            }

            nr += dr[dir];
            nc += dc[dir];
        }
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        
        unordered_map<int, int> freq;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < 8; k++) {
                    move(i, j, k, mat, freq);
                }
            }
        }

        int ans = -1, mx = 0;

        for (auto &[key, val] : freq) {
            if (val > mx || val == mx && key > ans) {
                ans = key;
                mx = val;
            }
        }

        return ans;
    }
};