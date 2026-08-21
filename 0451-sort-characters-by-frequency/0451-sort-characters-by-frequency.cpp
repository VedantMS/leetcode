class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (char &ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &[key, value] : mp) {
            pq.push({value, key});
        }

        string ans;

        while (!pq.empty()) {
            int key = pq.top().first;
            int value = pq.top().second;

            pq.pop();

            while (key) {
                ans.push_back(value);
                key--;
            }
        }

        return ans;
    }
};