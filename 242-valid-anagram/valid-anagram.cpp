class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> alpha;

        if(s.size() != t.size())    return false;

        for(auto ch : s)   alpha[ch]++;

        for(auto ch : t) {
            if(alpha[ch] == 0) {
                return false;
            }

            alpha[ch]--;
        }

        return true;
    }
};