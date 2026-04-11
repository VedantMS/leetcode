class Solution {
public:

    int findLeft(vector<int> &nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int left = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                left = mid;
                high = mid - 1;
            }

            else if(nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return left;
    }

    int findRight(vector<int> &nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int right = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                right = mid;
                low = mid + 1;
            }

            else if(nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);

        return {left, right};
    }
};