class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        vector<int> a(26, 0);
        
        int score = 0, num = 0, ch1 = -1, ch2 = -1;
        unordered_set<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                st.insert(s[i]);
                st.insert(goal[i]);
                score++;

                if (ch1 == -1) {
                    ch1 = i;
                }

                else {
                    ch2 = i;
                }
            }

            num += ++a[s[i] - 'a'] > 1 ? 1 : 0;
        }

        if (score == 0) {
            return num > 0;
        }

        if (score != 2) {
            return false;
        }

        return s[ch1] == goal[ch2] && s[ch2] == goal[ch1];
    }
};