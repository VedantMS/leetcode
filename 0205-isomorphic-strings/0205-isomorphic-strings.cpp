class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();

        unordered_map<char, int> ss;
        unordered_map<char, int> ts;

        for(int i = 0; i < n; i++) {
            if(ss.find(s[i]) == ss.end())       ss[s[i]] = i;
            if(ts.find(t[i]) == ts.end())       ts[t[i]] = i;

            if(ss[s[i]] != ts[t[i]])            return false;
        }

        return true;
    }
};