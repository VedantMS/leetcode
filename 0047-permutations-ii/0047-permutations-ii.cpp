class Solution {
public:
    void permutation(int index, vector<int> &nums, vector<bool> &visited, vector<int> &num, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(num);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            num.push_back(nums[i]);

            permutation(index + 1, nums, visited, num, ans);

            visited[i] = false;
            num.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> num;

        permutation(0, nums, visited, num, ans);

        return ans;
    }
};