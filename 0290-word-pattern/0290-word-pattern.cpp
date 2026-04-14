class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p;
        unordered_map<string, int> w;

        istringstream ss(s);

        int i = 0;
        int n = pattern.size();

        for(string word; ss >> word; i++) {
            if(i == n || p[pattern[i]] != w[word]) {
                return false;
            }

            p[pattern[i]] = w[word] = i + 1;
        }

        return i == n;
    }
};