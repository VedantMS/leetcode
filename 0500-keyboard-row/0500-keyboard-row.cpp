class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a = "qwertyuiop", b = "asdfghjkl", c = "zxcvbnm";

        vector<int> alpha(26, 0);

        for (char &ch : a) {
            alpha[ch - 'a'] = 1;
        }

        for (char &ch : b) {
            alpha[ch - 'a'] = 2;
        }

        for (char &ch : c) {
            alpha[ch - 'a'] = 3;
        }

        vector<string> ans;

        for (string &word : words) {
            int num = word[0] < 'a' ? alpha[word[0] + 32 - 'a'] : alpha[word[0] - 'a'];
            bool flag = true;

            for (char ch : word) {
                if (ch < 'a') {
                    ch += 32;
                }

                if (alpha[ch - 'a'] != num) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};