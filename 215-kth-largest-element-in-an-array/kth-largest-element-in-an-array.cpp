class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s(nums.begin(), nums.end());
        vector<int> ans(s.begin(), s.end());

        return ans[nums.size() - k];
    }
};