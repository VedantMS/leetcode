class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;

        for (int i = 0; i < groupSizes.size(); i++) {
            int num = groupSizes[i];
            mp[num].push_back(i);

            if (mp[num].size() == num) {
                ans.push_back(mp[num]);
                mp[num].clear();
            }
        }

        return ans;
    }
};