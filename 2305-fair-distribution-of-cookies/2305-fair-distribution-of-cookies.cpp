class Solution {
public:
    int ans = INT_MAX;

    void cookie(vector<int> &cookies, int k, int index, vector<int> &children) {
        if (index == cookies.size()) {
            ans = min(ans, *max_element(children.begin(), children.end()));
            return;
        }

        for (int i = 0; i < k; i++) {
            children[i] += cookies[index];
            cookie(cookies, k, index + 1, children);
            children[i] -= cookies[index];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);

        cookie(cookies, k, 0, children);

        return ans;
    }
};