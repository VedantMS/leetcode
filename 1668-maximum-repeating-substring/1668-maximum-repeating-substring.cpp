class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string words = word;

        while(sequence.find(words) != string::npos) {
            ans++;
            words += word;
        }

        return ans;
    }
};