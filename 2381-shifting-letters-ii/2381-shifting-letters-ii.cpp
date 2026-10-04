class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> a(s.size(), 0);

        for (auto shift : shifts) {
            int dir = shift[2] == 0 ? -1 : 1;
            
            a[shift[0]] += dir;
            
            if (shift[1] + 1 < s.size()) {
                a[shift[1] + 1] -= dir;
            }
        }

        int num = 0;

        for (int i = 0; i < s.size(); i++) {
            num += a[i];

            s[i] = (s[i] - 'a' + num % 26 + 26) % 26 + 'a';
        }

        return s;
    }
};