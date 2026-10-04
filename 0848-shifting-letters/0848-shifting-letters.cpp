class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int num = 0;

        for (int i = shifts.size() - 1; i >= 0; i--) {
            num = (num + shifts[i]) % 26;

            s[i] = (s[i] - 'a' + num) % 26 + 'a';
        }

        return s;
    }
};