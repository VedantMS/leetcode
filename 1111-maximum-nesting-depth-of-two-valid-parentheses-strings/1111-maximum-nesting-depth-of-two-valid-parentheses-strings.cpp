class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int num = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                num++;
            }

            ans[i] = num % 2;

            if (seq[i] == ')') {
                num--;
            }
        }

        return ans;
    }
};