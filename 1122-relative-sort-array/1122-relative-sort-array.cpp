class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        for (int &num : arr1) {
            mp[num]++;
        }

        vector<int> ans;

        for (int &num : arr2) {
            ans.push_back(num);

            if (mp[num]) {
                mp[num]--;
            }

            while (mp[num]) {
                ans.push_back(num);
                mp[num]--;
            }
        }

        for (auto &[key, value] : mp) {
            while (value) {
                ans.push_back(key);
                value--;
            }
        }

        return ans;
    }
};