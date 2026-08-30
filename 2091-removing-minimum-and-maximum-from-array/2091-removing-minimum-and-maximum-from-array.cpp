class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, mx = INT_MIN, index_mn, index_mx;

        for (int i = 0; i < n; i++) {
            if (mn > nums[i]) {
                mn = nums[i];
                index_mn = i;
            }

            if (mx < nums[i]) {
                mx = nums[i];
                index_mx = i;
            }
        }

        int a = max(index_mn, index_mx) + 1;
        int b = n - min(index_mn, index_mx);
        int c = min(index_mn, index_mx) + 1 + n - max(index_mn, index_mx);

        return min(a, min(b, c));
    }
};