class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        
        for (string &pattern : patterns) {
            if (word.contains(pattern)) {
                ans++;
            }
        }

        return ans;
    }
};