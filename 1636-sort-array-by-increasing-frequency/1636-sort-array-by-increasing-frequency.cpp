class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int &num : nums) {
            mp[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &[key, value] : mp) {
            bucket[value].push_back(key);
        }

        vector<int> ans;

        for (int i = 1; i <= nums.size(); i++) {
            if (bucket[i].empty()) {
                continue;
            }

            sort(bucket[i].begin(), bucket[i].end(), greater<int> ());

            for (int value : bucket[i]) {
                for (int j = 0; j < i; j++) {
                    ans.push_back(value);
                }
            }
        }

        return ans;
    }
};