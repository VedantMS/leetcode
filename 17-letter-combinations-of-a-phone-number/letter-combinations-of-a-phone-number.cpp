class Solution {
public:
    void backtrack(string &digits, int idx, string s, vector<string> &ans, unordered_map<char, string> &digitToLetters) {
        if(idx == digits.length()) {
            ans.push_back(s);
            return;
        }

        string letters = digitToLetters.at(digits[idx]);
        for(char letter : letters) {
            backtrack(digits, idx + 1, s + letter, ans, digitToLetters);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        backtrack(digits, 0, "", ans, digitToLetters);

        return ans;
    }
};