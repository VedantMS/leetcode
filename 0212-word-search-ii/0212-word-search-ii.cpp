class TrieNode {
public:
    TrieNode *child[26]{};
    bool word = false;
};

class Solution {
public:
    static constexpr int dr[] = {-1, 1, 0, 0};
    static constexpr int dc[] = {0, 0, -1, 1};

    int rows, cols;

    vector<string> ans;
    
    void dfs(int r, int c, vector<vector<char>> &board, TrieNode *node, string &word) {
        char ch = board[r][c];
        int index = ch - 'a';

        if (!node->child[index]) {
            return;
        }

        board[r][c] = '.';
        node = node->child[index];

        word.push_back(ch);

        if (node->word) {
            ans.push_back(word);
            node->word = false;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < rows && nr >= 0 && nc < cols && nc >= 0 && board[nr][nc] != '.') {
                dfs(nr, nc, board, node, word);
            }
        }

        word.pop_back();

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();

        rows = board.size();
        cols = board[0].size();

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

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                string word = "";
                dfs(i, j, board, root, word);
            }
        }

        return ans;
    }
};