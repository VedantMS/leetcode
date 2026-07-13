class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> dist;
    
    bool shortestPath(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (!wordSet.contains(endWord)) {
            return false;
        }
        
        queue<string> q;
        q.push(beginWord);

        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int num = dist[word] + 1;

            string str = word;
            
            for (int i = 0; i < str.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    char temp = str[i];

                    str[i] = ch;

                    if (ch != temp && wordSet.contains(str) && !dist.contains(str)) {
                        dist[str] = num;
                        q.push(str);
                    }

                    str[i] = temp;
                }
            }
        }

        return dist.contains(endWord);
    }

    void ladder(string word, string beginWord, vector<string> &wordArr) {
        if (word == beginWord) {
            vector<string> arr = wordArr;
            reverse(arr.begin(), arr.end());
            ans.push_back(arr);
            return;
        }

        string str = word;

        for (int i = 0; i < str.size(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                char temp = str[i];

                str[i] = ch;

                if (ch != temp && dist.contains(str) && dist[str] + 1 == dist[word]) {
                    wordArr.push_back(str);
                    
                    ladder(str, beginWord, wordArr);

                    wordArr.pop_back();
                }

                str[i] = temp;
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (!shortestPath(beginWord, endWord, wordList)) {
            return {};
        }

        vector<string> arr = {endWord};

        ladder(endWord, beginWord, arr);

        return ans
    }
};