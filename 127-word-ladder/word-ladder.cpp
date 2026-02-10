class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;

        q.push(beginWord);
        int ans = 1;

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                string str = q.front();
                q.pop();

                if(str == endWord) {
                    return ans;
                }
                
                int len = str.size();
                for(int j = 0; j < len; j++) {
                    char temp = str[j];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        str[j] = ch;
                        if(wordSet.count(str)) {
                            q.push(str);
                            wordSet.erase(str);
                        }
                    }
                    str[j] = temp;
                }
            }

            ans++;
        }

        return 0;
    }
};