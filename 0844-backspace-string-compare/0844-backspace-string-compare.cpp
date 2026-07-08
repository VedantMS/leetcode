class Solution {
public:
    string str(string str) {
        string a = "";

        for (char &ch : str) {
            if (ch == '#') {
                if (!a.empty()) {
                    a.pop_back();
                }
            }

            else {
                a.push_back(ch);
            }
        }

        return a;
    }

    bool backspaceCompare(string s, string t) {
        return str(s) ==  str(t);
    }
};