class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<string, int> ans;

        for (string word : words) {
            string s = "";

            for (char ch : word) {
                s += a[ch - 'a'];
            }

            ans[s]++;
        }

        return ans.size();
    }
};