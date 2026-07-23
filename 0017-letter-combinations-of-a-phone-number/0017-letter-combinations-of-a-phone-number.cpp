class Solution {
public:
    void backtrack(string digits, int index, unordered_map<char, string> &mp, string &s, vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(s);
            return;
        }

        for (char &ch : mp[digits[index]]) {
            s.push_back(ch);

            backtrack(digits, index + 1, mp, s, ans);

            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;

        string s = "";

        backtrack(digits, 0, mp, s, ans);

        return ans;
    }
};