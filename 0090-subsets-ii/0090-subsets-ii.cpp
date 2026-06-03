class Solution {
public:
    void sets(vector<int> &nums, int n, vector<vector<int>> &ans, vector<int> &num) {
        if(n == nums.size()) {
            ans.push_back(num);
            return;
        }

        num.push_back(nums[n]);
        sets(nums, n + 1, ans, num);
        
        num.pop_back();

        int index = n + 1;
        while(index < nums.size() && nums[index] == nums[n]) {
            index++;
        }
        
        sets(nums, index, ans, num);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> num;

        sort(nums.begin(), nums.end());

        sets(nums, 0, ans, num);

        return ans;
    }
};