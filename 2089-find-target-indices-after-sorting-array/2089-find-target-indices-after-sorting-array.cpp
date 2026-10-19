class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int num = 0, a = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                num++;
            }

            else if (nums[i] == target) {
                a++;
            }
        }

        vector<int> ans;

        for (int i = num; i < num + a; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};