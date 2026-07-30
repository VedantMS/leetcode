class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0], high = matrix[rows - 1][cols - 1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            int num = 0, j = rows - 1;

            for (int i = 0; i < rows; i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }

                num += j + 1;
            }

            if (num < k) {
                low = mid + 1;
            }

            else {
                high = mid;
            }
        }

        return low;
    }
};