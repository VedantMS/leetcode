class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class Solution {
public:
    string ans;

    void dfs(TrieNode *root, string &s) {
        if (s.size() > ans.size()) {
            ans = s;
        }
        
        for (int i = 0; i < 26; i++) {
            if (root->child[i] && root->child[i]->word) {
                s.push_back(i + 'a');
                dfs(root->child[i], s);
                s.pop_back();
            }
        }
    }

    string longestWord(vector<string>& words) {
        TrieNode *root = new TrieNode();

        for (string word : words) {
            TrieNode *node = root;

            for (char ch : word) {
                int index = ch - 'a';

                if (!node->child[index]) {
                    node->child[index] = new TrieNode();
                }

                node = node->child[index];
            }

            node->word = true;
        }

        string s = "";

        dfs(root, s);

        return ans;
    }
};