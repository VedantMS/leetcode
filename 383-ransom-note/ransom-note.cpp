class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> alphabets;

        for(auto ch : magazine) {
            alphabets[ch]++;
        }

        for(auto ch : ransomNote) {
            if(alphabets[ch] == 0) {
                return false;
            }

            alphabets[ch]--;
        }

        return true;
    }
};