class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int, int> rank;

        sort(temp.begin(), temp.end());

        for (int &num : temp) {
            if (!rank.contains(num)) {
                rank[num] = rank.size() + 1;
            }
        }

        for (int &num : arr) {
            num = rank[num];
        }

        return arr;
    }
};