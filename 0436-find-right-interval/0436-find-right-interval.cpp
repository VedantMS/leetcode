class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans; 

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], i});
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];

            auto it = lower_bound(a.begin(), a.end(), make_pair(end, -1));

            if (it != a.end()) {
                ans.push_back(it->second);
            }

            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};