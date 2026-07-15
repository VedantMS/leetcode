class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;

        for (auto &num : nums) {
            if (num % 2 == 0) {
                sum += num;
            }
        }

        vector<int> ans;

        for (auto &query : queries) {
            int val = query[0];
            int index = query[1];

            int num = nums[index] + val;

            if (nums[index] % 2 == 0) {
                if (num % 2 == 0) {
                    sum += val;
                }

                else {
                    sum -= nums[index];
                }
            }

            else {
                if (num % 2 == 0) {
                    sum += num;
                }
            }

            nums[index] += val;

            ans.push_back(sum);
        }

        return ans;
    }
};