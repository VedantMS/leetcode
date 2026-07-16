class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());

        if (st.size() == n && valueDiff == 0) {
            return false;
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n && j <= i + indexDiff; j++) {
                if (abs(nums[i] - nums[j]) <= valueDiff) {
                    return true;
                }
            }
        }

        return false;
    }
};