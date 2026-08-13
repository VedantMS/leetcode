class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        return str1 == str2.substr(0, str1.size()) && str1 == str2.substr(str2.size() - str1.size());
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i].size() <= words[j].size()) {
                    ans += isPrefixAndSuffix(words[i], words[j]);
                }
            }
        }

        return ans;
    }
};