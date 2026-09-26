class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";
        int i = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                int j = i + 1;
                string temp = "";

                while (s[j] != ')') {
                    temp += s[j++];
                }

                string str = "?";

                if (mp.contains(temp)) {
                    str = mp[temp];
                }

                ans += str;
                i = j + 1;

                continue;
            }

            ans += s[i++];
        }

        return ans;
    }
};