class Solution {
public:
    set<vector<int>> ans;

    void subsequence(vector<int> &nums, int index, int num, vector<int> &a) {
        if (index == nums.size()) {
            if (a.size() > 1) {
                ans.insert(a);
            }

            return;
        }

        subsequence(nums, index + 1, num, a);

        if (nums[index] >= num) {
            a.push_back(nums[index]);
            
            subsequence(nums, index + 1, nums[index], a);
            
            a.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> a;

        subsequence(nums, 0, -101, a);

        return vector<vector<int>> (ans.begin(), ans.end());
    }
};