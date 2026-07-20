class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        vector<bool> a(n, false);
        vector<int> ans;

        for (auto &num : nums) {
            if (a[num]) {
                ans.push_back(num);
            }

            a[num] = true;
        }

        return ans;
    }
};