class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode(), *node;

        for (auto word : dictionary) {
            node = root;

            for (char ch : word) {
                int index = ch - 'a';

                if (!node->child[index]) {
                    node->child[index] = new TrieNode();
                }

                node = node->child[index];
            }


            node->word = true;
        }

        string word = "", ans = "";

        for (char ch : sentence) {
            if (ch == ' ') {
                node = root;
                string s = "";

                for (char a : word) {
                    int index = a - 'a';

                    if (!node->child[index]) {
                        break;
                    }

                    s += a;
                    node = node->child[index];

                    if (node->word) {
                        break;
                    }
                }

                ans += (s != "" && node->word ? s : word) + ' ';

                word = "";

                continue;
            }

            word += ch;
        }

        node = root;
        
        string s = "";

        for (char ch : word) {
            int index = ch - 'a';

            if (!node->child[index]) {
                break;
            }

            s.push_back(ch);
            node = node->child[index];

            if (node->word) {
                break;
            }
        }

        ans += s != "" && node->word ? s : word;

        return ans;
    }
};