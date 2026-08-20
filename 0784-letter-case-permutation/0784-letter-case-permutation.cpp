class Solution {
public:
    void backtrack(int index, string &s, vector<string> &ans) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }

        backtrack(index + 1, s, ans);
        
        if (isalpha(s[index])) {
            char ch = s[index];

            s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]);

            backtrack(index + 1, s, ans);

            s[index] = ch;
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;

        backtrack(0, s, ans);

        return ans;
    }
};