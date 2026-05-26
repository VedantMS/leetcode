class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) {
                break;
            }
        }

        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};