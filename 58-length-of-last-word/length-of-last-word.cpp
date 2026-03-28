class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int ans = 0;
        int i = len - 1;


        while(s[i] == ' ') {
            i--;
        }

        while(i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }

        return ans;
    }
};