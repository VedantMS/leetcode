class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int val = nums[i];
            
            if(map.find(val) != map.end() && i - map[val] <= k) {
                return true;
            }

            map[val] = i;
        }

        return false;
    }
};