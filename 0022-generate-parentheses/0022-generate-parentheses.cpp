class Solution {
public:
    vector<string> ans;

    void parentheses(int n, int a, int b, string s) {
        if(s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if(a < n) {
            parentheses(n, a + 1, b, s + "(");
        }

        if(b < a) {
            parentheses(n, a, b + 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        parentheses(n, 0, 0, "");

        return ans;
    }
};