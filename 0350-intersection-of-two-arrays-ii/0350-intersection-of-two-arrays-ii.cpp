class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a(1001, 0);
        vector<int> ans;

        for (int &num : nums1) {
            a[num]++;
        }

        for (int &num : nums2) {
            if (a[num] > 0) {
                ans.push_back(num);
                a[num]--;
            }
        }

        return ans;
    }
};