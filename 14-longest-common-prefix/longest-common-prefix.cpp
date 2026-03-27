class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(string str : strs) {
            for(int i = 0; i < ans.size(); i++) {
                if(ans[i] != str[i]) {
                    for(int j = ans.size() - 1; j >= i; j--) {
                        ans.pop_back();
                    }
                }
            }
        }

        return ans;
    }
};