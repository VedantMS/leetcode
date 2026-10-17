class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> a(n, 0);

        for (int i = 0; i < n; i++) {
            a[edges[i]] += i;
        }

        long long num = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > num) {
                num = a[i];
                ans = i;
            }
        }

        return ans;
    }
};