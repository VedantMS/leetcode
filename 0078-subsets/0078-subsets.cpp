class Solution {
public:
    void sets(vector<int> &nums, int n, vector<vector<int>> &ans, vector<int> &num) {
        if(n == nums.size()) {
            ans.push_back(num);
            return;
        }

        sets(nums, n + 1, ans, num);

        num.push_back(nums[n]);
        sets(nums, n + 1, ans, num);

        num.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> num;

        sets(nums, 0, ans, num);

        return ans;
    }
};