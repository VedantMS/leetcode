class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int ans = 0;
        int n = s.size();

        unordered_set<char> charSet;

        for(int i = 0; i < n; i++) {
            while(charSet.find(s[i]) != charSet.end()) {
                charSet.erase(s[index]);
                index++;
            }

            charSet.insert(s[i]);
            ans = max(ans, i - index + 1);
        }

        return ans;
    }
};