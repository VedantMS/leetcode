class Solution {
public:
    vector<vector<int>> ans;

    void combination(vector<int>& candidates, int target, int start, int sum, vector<int> &a) {
        if(sum == target) {
            ans.push_back(a);
            return;
        }

        if(sum > target) {
            return;
        }

        int n = candidates.size();

        for(int i = start; i < n; i++) {
            a.push_back(candidates[i]);
            combination(candidates, target, i, sum + candidates[i], a);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;

        combination(candidates, target, 0, 0, a);

        return ans;
    }
};