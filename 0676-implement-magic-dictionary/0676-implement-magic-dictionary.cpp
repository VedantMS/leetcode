class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class MagicDictionary {
public:
    TrieNode *root;

    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto word : dictionary) {
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
    }
    
    bool dfs(TrieNode *node, string &searchWord, int i, bool flag) {
        if (i == searchWord.size()) {
            return node->word && flag;
        }
        
        int index = searchWord[i] - 'a';

        if (node->child[index] && dfs(node->child[index], searchWord, i + 1, flag)) {
            return true;
        }

        if (!flag) {
            for (int j = 0; j < 26; j++) {
                if (j != index && node->child[j] && dfs(node->child[j], searchWord, i + 1, true)) {
                    return true;
                } 
            }
        }

        return false;
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */