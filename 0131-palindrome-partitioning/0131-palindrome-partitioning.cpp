class Solution {
public:
    vector<vector<string>> ans;

    bool palindrome(string &s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high]) {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }

    void str(string &s, int index, vector<string> &pal) {
        if (index == s.size()) {
            ans.push_back(pal);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (palindrome(s, index, i)) {
                pal.push_back(s.substr(index, i - index + 1));

                str(s, i + 1, pal);

                pal.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> pal;

        str(s, 0, pal);

        return ans;
    }
};