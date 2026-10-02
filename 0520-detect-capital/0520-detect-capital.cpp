class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc = 0, lc = 0;

        for (char &ch : word) {
            if (ch >= 65 && ch <= 90) {
                uc++;
            }

            else {
                lc++;
            }
        }

        return word.size() == uc || word.size() == lc || uc == 1 && word[0] >= 65 && word[0] <= 90;
    }
};