class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int num = INT_MAX;

        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); i++) {
            if (mp.contains(list2[i])) {
                int sum = mp[list2[i]] + i;

                if (sum < num) {
                    num = sum;
                    ans.clear();
                    ans.push_back(list2[i]);
                }

                else if (sum == num) {
                    ans.push_back(list2[i]);
                }
            }
        }

        return ans;
    }
};