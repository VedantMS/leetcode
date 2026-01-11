class Solution {
public:
    string reverseWords(string s) {
        size_t first = s.find_first_not_of(' ');
        if (first == string::npos)
            return "";
        size_t last = s.find_last_not_of(' ');
        s = s.substr(first, last - first + 1);
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                s1 += s[i];
            else if (!s1.empty() && s1.back() != ' ')
                s1 += ' ';
        }
        s = s1;
        reverse(s.begin(), s.end());
        int start = 0;
        size_t end = s.find(' ');
        while(end != string::npos) {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            end = s.find(' ', start);
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};