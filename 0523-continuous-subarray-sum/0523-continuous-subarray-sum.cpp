class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int num = sum % k;

            if (remainderMap.contains(num)) {
                if (i - remainderMap[num] >= 2) {
                    return true;
                }
            }

            else {
                remainderMap[num] = i;
            }
        }

        return false;
    }
};