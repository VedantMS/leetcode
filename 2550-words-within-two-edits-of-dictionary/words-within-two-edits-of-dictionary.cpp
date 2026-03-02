class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int len1 = queries.size();
        int len2 = dictionary.size();

        vector<string> ans;

        for(int i = 0; i < len1; i++) {
            string str = queries[i];
            for(int j = 0; j < len2; j++) {
                string s = dictionary[j];
                int diff = 0;
                for(int k = 0; k < s.size(); k++) {
                    if(str[k] != s[k]) {
                        diff++;
                    }
                }
                if(diff <= 2) {
                    ans.push_back(str);
                    break;
                }
            }
        }

        return ans;
    }
};