class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);
        component[0] = 0;

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff) {
                component[i] = component[i - 1];
            }

            else {
                component[i] = component[i - 1] + 1;
            }
        }

        vector<bool> ans;

        for (auto &query : queries) {
            ans.push_back(component[query[0]] == component[query[1]]);
        }

        return ans;
    }
};