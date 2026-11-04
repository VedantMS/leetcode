class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class WordDictionary {
public:
    TrieNode *root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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

    bool dfs(int index, string &word, TrieNode *node) {
        if (index == word.size()) {
            return node->word;
        }

        if (word[index] == '.') {
            for (auto temp : node->child) {
                if (temp && dfs(index + 1, word, temp)) {
                    return true;
                }
            }
        }

        else {
            if (node->child[word[index] - 'a'] && dfs(index + 1, word, node->child[word[index] - 'a'])) {
                return true;
            }
        }

        return false;
    }
    
    bool search(string word) {
        return dfs(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */