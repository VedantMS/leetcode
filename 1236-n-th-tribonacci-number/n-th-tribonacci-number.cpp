class Solution {
public:
    int tribonacci(int n) {
        int arr[38] = {0, 1, 1};

        for(int i = 0; i < n - 2; i++) {
            arr[i + 3] = arr[i] + arr[i + 1] + arr[i + 2];
        }

        return arr[n];
    }
};