class Solution {
public:
    vector<vector<int>> ans;

    void combination(int n, int k, int num, int index, vector<int> &a) {
        if(index == k) {
            ans.push_back(a);
            return;
        }

        for(int i = num; i <= n; i++) {
            a.push_back(i);
            combination(n, k, i + 1, index + 1, a);
            a.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> a;

        combination(n, k, 1, 0, a);

        return ans;
    }
};