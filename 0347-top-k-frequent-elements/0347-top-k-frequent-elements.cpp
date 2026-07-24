class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int &num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto [key, value] : mp) {
            pq.push({value, key});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            auto num = pq.top();
            pq.pop();

            ans.push_back(num.second);
        }

        return ans;
    }
};