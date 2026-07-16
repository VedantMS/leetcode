class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> st;

        if (st.size() == n && valueDiff == 0) {
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            if (i > indexDiff) {
                st.erase(nums[i - indexDiff - 1]);
            }
            
            int num = nums[i];

            auto it = st.lower_bound(num - valueDiff);

            if (it != st.end() && *it <= num + valueDiff) {
                return true;
            }

            st.insert(num);
        }

        return false;
    }
};