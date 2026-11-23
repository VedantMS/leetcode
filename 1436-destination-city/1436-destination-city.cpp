class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;

        for (const auto &path : paths) {
            st.insert(path[0]);
        }

        for (const auto &path : paths) {
            if (st.find(path[1]) == st.end()) {
                return path[1];
            }
        }

        return {};
    }
};