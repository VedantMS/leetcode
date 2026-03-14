class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            
            while(left < right) {
                int num = nums[i] + nums[left] + nums[right];

                if(num == 0) {
                    ans.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }

                else if(num < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return vector<vector<int>> (ans.begin(), ans.end());
    }
};