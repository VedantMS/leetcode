class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> indices;
        int num = 0;

        indices.push_back(a[0].second);

        for (int i = 1; i < n; i++) {
            if (a[i].first - a[i - 1].first <= limit) {
                indices.push_back(a[i].second);
            }

            else {
                sort(indices.begin(), indices.end());

                int t = 0;

                for (int j = num; j < i; j++) {
                    nums[indices[t]] = a[j].first;
                    t++;
                }

                indices.clear();
                indices.push_back(a[i].second);

                num = i;
            }
        }

        sort(indices.begin(), indices.end());

        int t = 0;

        for (int i = num; i < n; i++) {
            nums[indices[t]] = a[i].first;
            t++;
        }

        return nums;
    }
};