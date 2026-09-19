class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        vector<int> dist(n, INT_MAX);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                dist[j] = min(dist[j], abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                
                if (dist[j] < dist[i + 1]) {
                    swap(points[j], points[i + 1]);
                    swap(dist[j], dist[i + 1]);
                }
            }

            ans += dist[i + 1];
        }

        return ans;
    }
};