class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        int n = intervals.size();

        vector<vector<int>> ans;
        vector<int> initial = intervals[0];

        for(int i = 1; i < n; i++) {
            vector<int> interval = intervals[i];

            if(interval[0] <= initial[1]) {
                initial[1] = max(initial[1], interval[1]);
            }

            else {
                ans.push_back(initial);
                initial = interval;
            }
        }

        ans.push_back(initial);

        return ans;
    }
};