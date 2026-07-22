class Solution {
public:
    vector<vector<string>> ans;

    bool palindrome(string s, int low, int high) {
        while (low <= high) {
            if (s[low] != s[high]) {
                return false;
            }

            low++;
            high--;
        }

        return true;
    }

    void str(string s, int low, int high, vector<string> &pal) {
        if (low == s.size()) {
            ans.push_back(pal);
            return;
        }

        for (int i = high; i < s.size(); i++) {
            if (palindrome(s, low, i)) {
                pal.push_back(s.substr(low, i - low + 1));

                str(s, i + 1, i + 1, pal);

                pal.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> pal;

        str(s, 0, 0, pal);

        return ans;
    }
};