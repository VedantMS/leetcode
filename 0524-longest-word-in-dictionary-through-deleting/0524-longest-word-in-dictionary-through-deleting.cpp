class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for (string word : dictionary) {
            bool flag = false;
            int i = 0, j = 0;
            string str = "";

            while (i < s.size() && j < word.size()) {
                while (i < s.size() && s[i] != word[j]) {
                    i++;
                }

                if (i < s.size() && j < word.size()){
                    str += s[i];
                }

                i++;
                j++;
            }

            if (str == word && (ans.size() < word.size() || ans.size() == word.size() && ans > word)) {
                ans = word;
            }
        }

        return ans;
    }
};