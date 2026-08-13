class Solution {
public:
    void backtrack(int index, string str, string &s, unordered_set<string> &st, vector<string> &ans) {
        if (index == s.size()) {
            ans.push_back(str);
        }

        string word = "";

        for (int i = index; i < s.size(); i++) {
            word.push_back(s[i]);

            if (st.contains(word)) {
                if (index > 0) {
                    backtrack(i + 1, str + " " + word, s, st, ans);
                }

                else {
                    backtrack(i + 1, word, s, st, ans);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> ans;

        backtrack(0, "", s, st, ans);

        return ans;
    }
};