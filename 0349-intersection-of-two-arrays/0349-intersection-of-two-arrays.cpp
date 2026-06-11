class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet;
        for (int num : nums1) {
            numSet.insert(num);
        }

        vector<int> ans;

        for (int num : nums2) {
            if(numSet.count(num)) {
                ans.push_back(num);
                numSet.erase(num);
            }
        }

        return ans;
    }
};