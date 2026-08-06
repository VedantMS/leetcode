class Solution {
public:
    void permutation(int index, vector<bool> &visited, vector<int>& nums, vector<int> &num, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(num);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                num.push_back(nums[i]);

                permutation(index + 1, visited, nums, num, ans);

                visited[i] = false;
                num.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> num;

        permutation(0, visited, nums, num, ans);

        return ans;
    }
};