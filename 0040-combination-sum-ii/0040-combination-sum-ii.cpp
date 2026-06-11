class Solution {
public:
    vector<vector<int>> ans;

    void combination(vector<int>& candidates, int target, int start, int sum, vector<int> &a) {
        if (sum == target) {
            ans.push_back(a);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            a.push_back(candidates[i]);
            combination(candidates, target, i + 1, sum + candidates[i], a);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> a;

        sort(candidates.begin(), candidates.end());

        combination(candidates, target, 0, 0, a);

        return ans;
    }
};