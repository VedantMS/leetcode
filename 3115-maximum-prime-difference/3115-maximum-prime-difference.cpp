class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left, right;

        vector<bool> prime(101, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i <= 100; i++) {
            if (prime[i]) {
                int k = 2;
                for (int j = i * 2; j <= 100; j = i * ++k) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (prime[nums[i]]) {
                left = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (prime[nums[i]]) {
                right = i;
                break;
            }
        }

        return right - left;
    }
};