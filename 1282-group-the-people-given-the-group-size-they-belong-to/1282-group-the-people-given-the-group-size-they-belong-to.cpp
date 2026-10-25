class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> a(n + 1), ans;

        for (int i = 0; i < n; i++) {
            int num = groupSizes[i];
            a[num].push_back(i);

            if (a[num].size() == num) {
                ans.push_back(a[num]);
                a[num].clear();
            }
        }

        return ans;
    }
};