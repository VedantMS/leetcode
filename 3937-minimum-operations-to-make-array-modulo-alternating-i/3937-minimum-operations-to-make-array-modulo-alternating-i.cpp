class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> even(k), odd(k);

        for(int i = 0; i < n; i += 2) {
            int r = nums[i] % k;

            for(int j = 0; j < k; j++) {
                int  d = abs(r - j);
                even[j] += min(d, k - d);
            }
        }

        for(int i = 1; i < n; i += 2) {
            int r = nums[i] % k;

            for(int j = 0; j < k; j++) {
                int  d = abs(r - j);
                odd[j] += min(d, k - d);
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(i != j) {
                    ans = min(ans, even[i] + odd[j]);
                }
            }
        }

        return ans;
    }
};