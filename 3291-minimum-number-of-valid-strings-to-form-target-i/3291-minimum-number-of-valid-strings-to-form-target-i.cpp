class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        TrieNode *root = new TrieNode;

        for (auto &word : words) {
            TrieNode *node = root;

            for (char &ch : word) {
                int index = ch - 'a';

                if (!node->child[index]) {
                    node->child[index] = new TrieNode();
                }

                node = node->child[index];
            }

            node->word = true;
        }

        int n = target.size();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == n + 1) {
                continue;
            }

            TrieNode *node = root;

            for (int j = i; j < n; j++) {
                int index = target[j] - 'a';

                if (!node->child[index]) {
                    break;
                }

                node = node->child[index];

                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }

        return dp[n] == n + 1 ? -1 : dp[n];
    }
};