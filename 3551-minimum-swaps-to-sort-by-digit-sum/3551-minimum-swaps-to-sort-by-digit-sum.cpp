class Solution {
public:
    int sum(int num) {
        int n = 0;

        while (num) {
            n += num % 10;
            num /= 10;
        }

        return n;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // sum, num, index
        vector<vector<int>> a(n, vector<int> (3));

        for (int i = 0; i < n; i++) {
            a[i] = {sum(nums[i]), nums[i], i};
        }

        sort(a.begin(), a.end());

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || a[i][2] == i) {
                continue;
            }

            int j = i, num = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = a[j][2];
                num++;
            }

            ans += num - 1;
        }

        return ans;
    }
};