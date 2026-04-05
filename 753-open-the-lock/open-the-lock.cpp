class Solution {
public:
    vector<string> neighbors(string &str) {
        vector<string> nv;
        for(int i = 0; i < 4; i++) {
            for(int diff = -1; diff <= 1; diff += 2) {
                string neighbor = str;
                neighbor[i] = (neighbor[i] - '0' + diff + 10) % 10 + '0';
                nv.push_back(neighbor);
            }
        }

        return nv;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set(deadends.begin(), deadends.end());
        int ans = 0;

        if (set.count("0000"))  return -1;

        queue<string> q;
        q.push("0000");

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                string str = q.front();
                q.pop();

                if(str == target)   return ans;
                
                vector<string> n = neighbors(str);

                for(auto neighbor : n) {
                    if(set.count(neighbor))     continue;

                    set.insert(neighbor);
                    q.push(neighbor);
                }
            }

            ans++;
        }

        return -1;
    }
};