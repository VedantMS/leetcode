class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n2; i++) {
            mp[nums2[i]] = i;
        }

        vector<int> ans(n1, -1);

        for (int i = 0; i < n1; i++) {
            for (int j = mp[nums1[i]]; j < n2; j++) {
                if (nums1[i] < nums2[j]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};