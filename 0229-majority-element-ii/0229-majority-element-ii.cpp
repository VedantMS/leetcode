class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums;
        }

        sort(nums.begin(), nums.end());
        
        vector<int> ans;

        int num = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                num++;
            }

            else {
                if (num > n / 3) {
                    ans.push_back(nums[i - 1]);
                }

                num = 1;
            }
        }

        if (num > n / 3) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};