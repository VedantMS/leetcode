class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        int near = 0;
        int far = 0;
        int jumps = 0;

        while(far < n) {
            int farthest = 0;

            for(int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;
    }
};