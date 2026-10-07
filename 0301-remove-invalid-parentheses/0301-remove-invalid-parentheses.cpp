class Solution {
public:
    void backtrack(int index, int num, int len, string &str, string &s, unordered_set<string> &ans) {
        if (index == s.size() || str.size() + (s.size() - index) < len) {
            if (num == 0 && len == str.size()) {
                ans.insert(str);
            }

            return;
        }

        if (!isalpha(s[index])) {
            backtrack(index + 1, num, len, str, s, ans);
        }

        if (s[index] == '(') {
            num++;
        }

        else if (s[index] == ')') {
            num--;
        }

        str.push_back(s[index]);

        if (num >= 0 && !ans.contains(str)) {
            backtrack(index + 1, num, len, str, s, ans);
        }

        str.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        string str = "";
        int open = 0, d = 0, len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            }

            else if (s[i] == ')') {
                if (open) {
                    open--;
                }

                else {
                    d++;
                }
            }
        }

        len = s.size() - open - d;

        backtrack(0, 0, len, str, s, ans);

        return ans.empty() ? vector<string> {""} : vector<string> (ans.begin(), ans.end());
    }
};