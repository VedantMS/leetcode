class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> mp;

        for (auto &response : responses) {
            unordered_set<string> st;

            for (string &s : response) {
                if (!st.contains(s)) {
                    st.insert(s);
                    mp[s]++;
                }
            }
        }

        string ans;
        int num = 0;

        for (auto &[key, value] : mp) {
            if (num < value) {
                ans = key;
                num = value;
            }
        }

        return ans;
    }
};