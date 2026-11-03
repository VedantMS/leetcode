class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (!temp->child[index]) {
                temp->child[index] = new TrieNode();
            }

            temp = temp->child[index];
        }

        temp->word = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (!temp->child[index]) {
                return false;
            }

            temp = temp->child[index];
        }

        return temp->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (!temp->child[index]) {
                return false;
            }

            temp = temp->child[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */