class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int len1 = queries.size();
        int len2 = dictionary.size();

        vector<string> ans;

        for(auto &q : queries) {
            for(auto &d : dictionary) {
                int diff = 0;
                for(int i = 0; i < q.size(); i++) {
                    if(q[i] != d[i]) {
                        diff++;
                    }
                }
                if(diff <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};