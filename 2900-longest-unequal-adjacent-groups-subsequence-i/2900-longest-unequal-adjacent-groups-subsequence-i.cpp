class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int num = -1;

        for (int i = 0; i < words.size(); i++) {
            if (groups[i] != num) {
                ans.push_back(words[i]);
                num = groups[i];
            }
        }

        return ans;
    }
};