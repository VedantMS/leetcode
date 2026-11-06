class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;

        for (int num : arr1) {
            string s = to_string(num);

            while (s != "") {
                st.insert(s);
                s.pop_back();
            }
        }

        int ans = 0;

        for (int num : arr2) {
            string s = to_string(num);

            while (s.size() > ans) {
                if (st.contains(s)) {
                    ans = max(ans, (int) s.size());
                }

                s.pop_back();
            }
        }

        return ans;
    }
};