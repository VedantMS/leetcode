class Solution {
public:
    void dfs(int num, vector<int> &ans, int n) {
        ans.push_back(num);

        if (num * 10 <= n) {
            dfs(num * 10, ans, n);
        }

        if (num % 10 != 9 && num + 1 <= n) {
            dfs(num + 1, ans, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        dfs(1, ans, n);

        return ans;
    }
};